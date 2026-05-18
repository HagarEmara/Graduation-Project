set BASE /home/mahmoudsamy/grad/ZC702

proc load_bin_pa {filename pa_addr} {
    set f [open $filename rb]
    fconfigure $f -translation binary
    set data [read $f]
    close $f
    set len [string length $data]
    puts "  Loading [expr {$len/1024}] KB to PA [format 0x%08x $pa_addr]"
    set addr $pa_addr
    set i 0
    set chunk_words 2048
    set start_time [clock seconds]
    while {$i < $len} {
        set wlist {}
        for {set j 0} {$j < $chunk_words && $i < $len} {incr j} {
            set remaining [expr {$len - $i}]
            if {$remaining >= 4} {
                binary scan $data @${i}iu1 word
            } else {
                set word 0
                for {set k 0} {$k < $remaining} {incr k} {
                    binary scan $data @[expr {$i+$k}]cu1 byte
                    set word [expr {$word | (($byte & 0xFF) << ($k*8))}]
                }
            }
            lappend wlist [format "0x%08x" [expr {$word & 0xFFFFFFFF}]]
            incr i 4
        }
        mwr -address-space PA $addr $wlist
        incr addr [expr {[llength $wlist] * 4}]
        if {[expr {$i % (1024*1024)}] < ($chunk_words*4)} {
            set elapsed [expr {[clock seconds] - $start_time}]
            puts "    [expr {$i/1024/1024}] / [expr {$len/1024/1024}] MB  (${elapsed}s)"
        }
    }
    puts "  Done in [expr {[clock seconds] - $start_time}]s"
}

puts "Step 1: Connecting..."
connect

puts "Step 2: PS7 init..."
targets -set -filter {name =~ "APU*"}
rst -system
after 3000
source "${BASE}/build/ztachip_zc702.gen/sources_1/bd/zynq_bd/ip/zynq_bd_ps7_0/ps7_init.tcl"
ps7_init
ps7_post_config

puts "Step 3: Programming bitstream..."
targets -set -filter {name =~ "xc7z*"}
fpga "${BASE}/build/ztachip_zc702.runs/impl_1/zc702_top.bit"
after 3000

puts "Step 4: Re-init PS7..."
targets -set -filter {name =~ "APU*"}
ps7_init
ps7_post_config
configparams force-mem-accesses 1
after 1000

puts "Step 5: Halt ARM..."
targets -set -filter {name =~ "ARM*#0"}
stop
after 500

puts "Step 5a: PA probe..."
foreach a {0x00100000 0x00104000 0x0BFC4360 0x0C000000 0x0C800000} {
    if {[catch {
        mwr -address-space PA $a 0xCAFEBABE
        set v [mrd -address-space PA -value $a]
        if {$v == 3405691582} {
            puts "  PA [format 0x%08x $a] : OK"
        } else {
            puts "  PA [format 0x%08x $a] : MISMATCH"
        }
    } err]} {
        puts "  PA [format 0x%08x $a] : FAIL"
    }
}

puts "Step 6: Load vector to PA 0x00100000..."
load_bin_pa "${BASE}/SW/build/seg1_vector.bin" 0x00100000

puts "Step 7: Load code+data to PA 0x0BFC4360..."
load_bin_pa "${BASE}/SW/build/seg2_code.bin" 0x0BFC4360

puts "Step 8: Resume..."
con

puts ""
puts "============================================"
puts " DONE! sudo screen /dev/ttyUSB0 115200"
puts "============================================"
