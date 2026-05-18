# =============================================================================
# Test 3 BD edits — enable M_AXI_GP0 and expose it as external ports.
# =============================================================================
open_bd_design [get_files zynq_bd.bd]
current_bd_design [get_bd_designs zynq_bd]

# 1. Enable M_AXI_GP0 on PS
set_property -dict [list \
  CONFIG.PCW_USE_M_AXI_GP0 {1} \
] [get_bd_cells ps7]

# 2. Expose M_AXI_GP0 + clock as external BD ports
make_bd_intf_pins_external [get_bd_intf_pins ps7/M_AXI_GP0]
make_bd_pins_external      [get_bd_pins      ps7/M_AXI_GP0_ACLK]

# Rename auto-created port names
set_property name M_AXI_GP0      [get_bd_intf_ports M_AXI_GP0_0]
set_property name M_AXI_GP0_ACLK [get_bd_ports      M_AXI_GP0_ACLK_0]

# 3. Validate + save
validate_bd_design
save_bd_design

puts "----------------------------------------------"
puts " Test 3 BD edits applied."
puts "----------------------------------------------"
