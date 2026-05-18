set BASE /home/mahmoudsamy/graduation_project_ztachip/ZC702

create_project ztachip_zc702 ${BASE}/build -part xc7z020clg484-1 -force
set_property board_part xilinx.com:zc702:part0:1.4 [current_project]

# Top-level wrapper
read_verilog ${BASE}/zc702_top.v

# RISC-V
read_verilog ${BASE}/src/top/riscv.v

# Config (ZC702 version: 64-bit, 100MHz)
read_vhdl ${BASE}/config_zc702.vhd

# Package
read_vhdl ${BASE}/src/ztachip_pkg.vhd

# ALU
read_vhdl ${BASE}/src/alu/alu.vhd

# DP
read_vhdl ${BASE}/src/dp/dp.vhd
read_vhdl ${BASE}/src/dp/dp_core.vhd
read_vhdl ${BASE}/src/dp/dp_fetch.vhd
read_vhdl ${BASE}/src/dp/dp_fifo.vhd
read_vhdl ${BASE}/src/dp/dp_gen.vhd
read_vhdl ${BASE}/src/dp/dp_gen_core.vhd
read_vhdl ${BASE}/src/dp/dp_sink.vhd
read_vhdl ${BASE}/src/dp/dp_source.vhd

# IALU
read_vhdl ${BASE}/src/ialu/ialu.vhd
read_vhdl ${BASE}/src/ialu/iregister_file.vhd
read_vhdl ${BASE}/src/ialu/iregister_ram.vhd

# PCORE
read_vhdl ${BASE}/src/pcore/core.vhd
read_vhdl ${BASE}/src/pcore/instr.vhd
read_vhdl ${BASE}/src/pcore/instr_decoder2.vhd
read_vhdl ${BASE}/src/pcore/instr_dispatch2.vhd
read_vhdl ${BASE}/src/pcore/instr_fetch.vhd
read_vhdl ${BASE}/src/pcore/pcore.vhd
read_vhdl ${BASE}/src/pcore/register_bank.vhd
read_vhdl ${BASE}/src/pcore/register_file.vhd
read_vhdl ${BASE}/src/pcore/rom.vhd
read_vhdl ${BASE}/src/pcore/stream.vhd
read_vhdl ${BASE}/src/pcore/xregister_file.vhd

# SOC
read_vhdl ${BASE}/src/soc/soc_base.vhd
read_vhdl ${BASE}/src/soc/tcm.vhd
read_vhdl ${BASE}/src/soc/axi/axi_apb_bridge.vhd
read_vhdl ${BASE}/src/soc/axi/axi_merge.vhd
read_vhdl ${BASE}/src/soc/axi/axi_merge_read.vhd
read_vhdl ${BASE}/src/soc/axi/axi_merge_write.vhd
read_vhdl ${BASE}/src/soc/axi/axi_read.vhd
read_vhdl ${BASE}/src/soc/axi/axi_split.vhd
read_vhdl ${BASE}/src/soc/axi/axi_split_read.vhd
read_vhdl ${BASE}/src/soc/axi/axi_split_write.vhd
read_vhdl ${BASE}/src/soc/axi/axi_stream_read.vhd
read_vhdl ${BASE}/src/soc/axi/axi_stream_write.vhd
read_vhdl ${BASE}/src/soc/axi/axi_write.vhd
read_vhdl ${BASE}/src/soc/axi/axi_ram_read.vhd
read_vhdl ${BASE}/src/soc/axi/axi_ram_write.vhd
read_vhdl ${BASE}/src/soc/axi/axi_resize_read.vhd
read_vhdl ${BASE}/src/soc/axi/axi_resize_write.vhd

# Peripherals
read_vhdl ${BASE}/src/soc/peripherals/camera.vhd
read_vhdl ${BASE}/src/soc/peripherals/gpio.vhd
read_vhdl ${BASE}/src/soc/peripherals/vga.vhd
read_vhdl ${BASE}/src/soc/peripherals/time.vhd
read_vhdl ${BASE}/src/soc/peripherals/uart.vhd
read_vhdl ${BASE}/src/soc/peripherals/ethlite.vhd

# Top-level ztachip
read_vhdl ${BASE}/src/top/axilite.vhd
read_vhdl ${BASE}/src/top/cell.vhd
read_vhdl ${BASE}/src/top/ddr_rx.vhd
read_vhdl ${BASE}/src/top/ddr_tx.vhd
read_vhdl ${BASE}/src/top/sram.vhd
read_vhdl ${BASE}/src/top/sram_core.vhd
read_vhdl ${BASE}/src/top/ztachip.vhd

# Utility
read_vhdl ${BASE}/src/util/shifter_l.vhd
read_vhdl ${BASE}/src/util/shifter.vhd
read_vhdl ${BASE}/src/util/ramw2.vhd
read_vhdl ${BASE}/src/util/ramw.vhd
read_vhdl ${BASE}/src/util/ram2r1w.vhd
read_vhdl ${BASE}/src/util/multiplier.vhd
read_vhdl ${BASE}/src/util/fifow.vhd
read_vhdl ${BASE}/src/util/fifo.vhd
read_vhdl ${BASE}/src/util/delayv.vhd
read_vhdl ${BASE}/src/util/delayi.vhd
read_vhdl ${BASE}/src/util/delay.vhd
read_vhdl ${BASE}/src/util/arbiter.vhd
read_vhdl ${BASE}/src/util/afifo.vhd
read_vhdl ${BASE}/src/util/afifo2.vhd
read_vhdl ${BASE}/src/util/adder.vhd

# FPU
read_vhdl ${BASE}/src/fpu/falu_core.vhd
read_vhdl ${BASE}/src/fpu/falu_vector.vhd
read_vhdl ${BASE}/src/fpu/falu2.vhd
read_vhdl ${BASE}/src/fpu/falu.vhd
read_vhdl ${BASE}/src/fpu/fp12.vhd
read_vhdl ${BASE}/src/fpu/fp2int.vhd
read_vhdl ${BASE}/src/fpu/fp_floor.vhd
read_vhdl ${BASE}/src/fpu/fpmax.vhd
read_vhdl ${BASE}/src/fpu/fpu.vhd

# Platform primitives (Xilinx)
read_verilog ${BASE}/platform/Xilinx/CCD_SYNC.v
read_verilog ${BASE}/platform/Xilinx/SYNC_LATCH.v
read_verilog ${BASE}/platform/Xilinx/SHIFT.v
read_verilog ${BASE}/platform/Xilinx/DPRAM_BE.v
read_verilog ${BASE}/platform/Xilinx/DPRAM_DUAL_CLOCK.v
read_verilog ${BASE}/platform/Xilinx/DPRAM.v
read_verilog ${BASE}/platform/Xilinx/SPRAM_BE.v
read_verilog ${BASE}/platform/Xilinx/SPRAM.v
read_verilog ${BASE}/platform/Xilinx/FP32_MUL.v
read_verilog ${BASE}/platform/Xilinx/FP32_ADDSUB.v

# Constraints
read_xdc ${BASE}/zc702.xdc

# Floating point IPs
create_ip -name floating_point -vendor xilinx.com -library ip -version 7.1 \
   -module_name float_addsub
set_property -dict [list \
   CONFIG.Operation_Type {Add_Subtract} \
   CONFIG.Maximum_Latency {false} \
   CONFIG.C_Latency {4} \
   CONFIG.Flow_Control {NonBlocking}] [get_ips float_addsub]
generate_target all [get_ips float_addsub]

create_ip -name floating_point -vendor xilinx.com -library ip -version 7.1 \
   -module_name float_mul
set_property -dict [list \
   CONFIG.Operation_Type {Multiply} \
   CONFIG.Maximum_Latency {false} \
   CONFIG.C_Latency {4} \
   CONFIG.Flow_Control {NonBlocking}] [get_ips float_mul]
generate_target all [get_ips float_mul]

# Block design
source ${BASE}/create_bd.tcl

# Add generated wrapper
set wrapper [get_files -of_objects [get_filesets sources_1] zynq_bd_wrapper.v]
if {$wrapper eq ""} {
   add_files -norecurse ${BASE}/build/ztachip_zc702.gen/sources_1/bd/zynq_bd/hdl/zynq_bd_wrapper.v
}

# Set top
set_property top zc702_top [current_fileset]
update_compile_order -fileset sources_1

# Constraints
add_files -fileset constrs_1 -norecurse ${BASE}/zc702.xdc

# Verify no stale references
set stale 0
foreach f [get_files] {
    if {[string match "*/ztachip/*" $f]} {
        puts "STALE: $f"
        incr stale
    }
}
if {$stale == 0} {
    puts "CLEAN — Zero ztachip/ references"
} else {
    puts "WARNING — $stale stale references"
}

puts "================================================================"
puts " Project created successfully!"
puts " Next: Run Synthesis"
puts "================================================================"
