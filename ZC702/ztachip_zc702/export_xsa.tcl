open_project /home/mahmoudsamy/grad/ZC702/ztachip_zc702/ztachip_zc702.xpr
puts "===== Project opened ====="
puts "Top module: [get_property top [current_fileset]]"
puts "===== Writing hardware platform (XSA) with bitstream ====="
write_hw_platform -fixed -include_bit -force -file /home/mahmoudsamy/grad/ZC702/ztachip_zc702/ztachip_zc702.xsa
puts "===== XSA exported ====="
close_project
