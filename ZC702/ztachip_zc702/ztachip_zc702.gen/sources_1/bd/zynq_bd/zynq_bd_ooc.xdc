################################################################################

# This XDC is used only for OOC mode of synthesis, implementation
# This constraints file contains default clock frequencies to be used during
# out-of-context flows such as OOC Synthesis and Hierarchical Designs.
# This constraints file is not used in normal top-down synthesis (default flow
# of Vivado)
################################################################################
create_clock -name S_AXI_HP0_ACLK -period 10 [get_ports S_AXI_HP0_ACLK]
create_clock -name M_AXI_GP0_ACLK -period 10 [get_ports M_AXI_GP0_ACLK]
create_clock -name ps7_FCLK_CLK0 -period 10 [get_pins ps7/FCLK_CLK0]
create_clock -name ps7_FCLK_CLK1 -period 5 [get_pins ps7/FCLK_CLK1]

################################################################################