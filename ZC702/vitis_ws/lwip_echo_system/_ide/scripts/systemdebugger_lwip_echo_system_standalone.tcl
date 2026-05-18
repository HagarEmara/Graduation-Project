# Usage with Vitis IDE:
# In Vitis IDE create a Single Application Debug launch configuration,
# change the debug type to 'Attach to running target' and provide this 
# tcl script in 'Execute Script' option.
# Path of this script: /home/mahmoudsamy/grad/ZC702/vitis_ws/lwip_echo_system/_ide/scripts/systemdebugger_lwip_echo_system_standalone.tcl
# 
# 
# Usage with xsct:
# To debug using xsct, launch xsct and run below command
# source /home/mahmoudsamy/grad/ZC702/vitis_ws/lwip_echo_system/_ide/scripts/systemdebugger_lwip_echo_system_standalone.tcl
# 
connect -url tcp:127.0.0.1:3121
targets -set -nocase -filter {name =~"APU*"}
rst -system
after 3000
targets -set -filter {jtag_cable_name =~ "Digilent JTAG-SMT1 210203A7C0B2A" && level==0 && jtag_device_ctx=="jsn-JTAG-SMT1-210203A7C0B2A-23727093-0"}
fpga -file /home/mahmoudsamy/grad/ZC702/vitis_ws/lwip_echo/_ide/bitstream/ztachip_zc702.bit
targets -set -nocase -filter {name =~"APU*"}
loadhw -hw /home/mahmoudsamy/grad/ZC702/vitis_ws/ztachip_zc702_platform/export/ztachip_zc702_platform/hw/ztachip_zc702.xsa -mem-ranges [list {0x40000000 0xbfffffff}] -regs
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*"}
source /home/mahmoudsamy/grad/ZC702/vitis_ws/lwip_echo/_ide/psinit/ps7_init.tcl
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "*A9*#0"}
dow /home/mahmoudsamy/grad/ZC702/vitis_ws/lwip_echo/Debug/lwip_echo.elf
configparams force-mem-access 0
bpadd -addr &main
