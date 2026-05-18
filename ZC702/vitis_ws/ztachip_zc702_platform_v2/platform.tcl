# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct /home/mahmoudsamy/grad/ZC702/vitis_ws/ztachip_zc702_platform_v2/platform.tcl
# 
# OR launch xsct and run below command.
# source /home/mahmoudsamy/grad/ZC702/vitis_ws/ztachip_zc702_platform_v2/platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {ztachip_zc702_platform_v2}\
-hw {/home/mahmoudsamy/grad/ZC702/ztachip_zc702.xsa}\
-proc {ps7_cortexa9_0} -os {standalone} -out {/home/mahmoudsamy/grad/ZC702/vitis_ws}

platform write
platform generate -domains 
platform active {ztachip_zc702_platform_v2}
domain active {zynq_fsbl}
bsp reload
platform generate
platform active {ztachip_zc702_platform_v2}
platform generate
platform active {ztachip_zc702_platform_v2}
domain active {standalone_domain}
bsp reload
bsp setlib -name xilffs -ver 4.5
bsp write
bsp reload
catch {bsp regenerate}
platform generate -domains standalone_domain 
platform clean
platform generate
platform clean
platform generate
platform clean
platform generate
platform clean
platform generate
platform generate
platform active {ztachip_zc702_platform_v2}
domain active {zynq_fsbl}
bsp reload
domain active {standalone_domain}
bsp reload
platform config -desc {ztachip_zc702_platform_v2}
platform write
platform config -updatehw {/home/mahmoudsamy/grad/ZC702/zc702_top.xsa}
platform clean
platform generate
platform generate -domains 
platform clean
platform generate
platform clean
platform generate
platform clean
platform generate
platform active {ztachip_zc702_platform_v2}
platform config -updatehw {/home/mahmoudsamy/grad/ZC702/vitis_ws/ztachip_zc702_platform_v2/hw/zc702_top.xsa}
platform clean
platform clean
