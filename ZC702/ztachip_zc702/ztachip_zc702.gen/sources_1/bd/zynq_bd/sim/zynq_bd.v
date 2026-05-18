//Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2021.1 (lin64) Build 3247384 Thu Jun 10 19:36:07 MDT 2021
//Date        : Sun May  3 11:13:21 2026
//Host        : mahmoudsamy-Legion-Slim-5-14APH8 running 64-bit Ubuntu 24.04.4 LTS
//Command     : generate_target zynq_bd.bd
//Design      : zynq_bd
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "zynq_bd,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=zynq_bd,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=1,numReposBlks=1,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,da_ps7_cnt=1,synth_mode=OOC_per_IP}" *) (* HW_HANDOFF = "zynq_bd.hwdef" *) 
module zynq_bd
   (DDR_addr,
    DDR_ba,
    DDR_cas_n,
    DDR_ck_n,
    DDR_ck_p,
    DDR_cke,
    DDR_cs_n,
    DDR_dm,
    DDR_dq,
    DDR_dqs_n,
    DDR_dqs_p,
    DDR_odt,
    DDR_ras_n,
    DDR_reset_n,
    DDR_we_n,
    FCLK_CLK0,
    FCLK_CLK1,
    FCLK_RESET0_N,
    FIXED_IO_ddr_vrn,
    FIXED_IO_ddr_vrp,
    FIXED_IO_mio,
    FIXED_IO_ps_clk,
    FIXED_IO_ps_porb,
    FIXED_IO_ps_srstb,
    M_AXI_GP0_ACLK,
    M_AXI_GP0_araddr,
    M_AXI_GP0_arburst,
    M_AXI_GP0_arcache,
    M_AXI_GP0_arid,
    M_AXI_GP0_arlen,
    M_AXI_GP0_arlock,
    M_AXI_GP0_arprot,
    M_AXI_GP0_arqos,
    M_AXI_GP0_arready,
    M_AXI_GP0_arsize,
    M_AXI_GP0_arvalid,
    M_AXI_GP0_awaddr,
    M_AXI_GP0_awburst,
    M_AXI_GP0_awcache,
    M_AXI_GP0_awid,
    M_AXI_GP0_awlen,
    M_AXI_GP0_awlock,
    M_AXI_GP0_awprot,
    M_AXI_GP0_awqos,
    M_AXI_GP0_awready,
    M_AXI_GP0_awsize,
    M_AXI_GP0_awvalid,
    M_AXI_GP0_bid,
    M_AXI_GP0_bready,
    M_AXI_GP0_bresp,
    M_AXI_GP0_bvalid,
    M_AXI_GP0_rdata,
    M_AXI_GP0_rid,
    M_AXI_GP0_rlast,
    M_AXI_GP0_rready,
    M_AXI_GP0_rresp,
    M_AXI_GP0_rvalid,
    M_AXI_GP0_wdata,
    M_AXI_GP0_wid,
    M_AXI_GP0_wlast,
    M_AXI_GP0_wready,
    M_AXI_GP0_wstrb,
    M_AXI_GP0_wvalid,
    S_AXI_HP0_ACLK,
    S_AXI_HP0_araddr,
    S_AXI_HP0_arburst,
    S_AXI_HP0_arcache,
    S_AXI_HP0_arid,
    S_AXI_HP0_arlen,
    S_AXI_HP0_arlock,
    S_AXI_HP0_arprot,
    S_AXI_HP0_arqos,
    S_AXI_HP0_arready,
    S_AXI_HP0_arsize,
    S_AXI_HP0_arvalid,
    S_AXI_HP0_awaddr,
    S_AXI_HP0_awburst,
    S_AXI_HP0_awcache,
    S_AXI_HP0_awid,
    S_AXI_HP0_awlen,
    S_AXI_HP0_awlock,
    S_AXI_HP0_awprot,
    S_AXI_HP0_awqos,
    S_AXI_HP0_awready,
    S_AXI_HP0_awsize,
    S_AXI_HP0_awvalid,
    S_AXI_HP0_bid,
    S_AXI_HP0_bready,
    S_AXI_HP0_bresp,
    S_AXI_HP0_bvalid,
    S_AXI_HP0_rdata,
    S_AXI_HP0_rid,
    S_AXI_HP0_rlast,
    S_AXI_HP0_rready,
    S_AXI_HP0_rresp,
    S_AXI_HP0_rvalid,
    S_AXI_HP0_wdata,
    S_AXI_HP0_wid,
    S_AXI_HP0_wlast,
    S_AXI_HP0_wready,
    S_AXI_HP0_wstrb,
    S_AXI_HP0_wvalid);
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR ADDR" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME DDR, AXI_ARBITRATION_SCHEME TDM, BURST_LENGTH 8, CAN_DEBUG false, CAS_LATENCY 11, CAS_WRITE_LATENCY 11, CS_ENABLED true, DATA_MASK_ENABLED true, DATA_WIDTH 8, MEMORY_TYPE COMPONENTS, MEM_ADDR_MAP ROW_COLUMN_BANK, SLOT Single, TIMEPERIOD_PS 1250" *) inout [14:0]DDR_addr;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR BA" *) inout [2:0]DDR_ba;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR CAS_N" *) inout DDR_cas_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR CK_N" *) inout DDR_ck_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR CK_P" *) inout DDR_ck_p;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR CKE" *) inout DDR_cke;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR CS_N" *) inout DDR_cs_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR DM" *) inout [3:0]DDR_dm;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR DQ" *) inout [31:0]DDR_dq;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR DQS_N" *) inout [3:0]DDR_dqs_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR DQS_P" *) inout [3:0]DDR_dqs_p;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR ODT" *) inout DDR_odt;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR RAS_N" *) inout DDR_ras_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR RESET_N" *) inout DDR_reset_n;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ddrx:1.0 DDR WE_N" *) inout DDR_we_n;
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.FCLK_CLK0 CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.FCLK_CLK0, CLK_DOMAIN zynq_bd_ps7_0_FCLK_CLK0, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, INSERT_VIP 0, PHASE 0.0" *) output FCLK_CLK0;
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.FCLK_CLK1 CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.FCLK_CLK1, CLK_DOMAIN zynq_bd_ps7_0_FCLK_CLK1, FREQ_HZ 200000000, FREQ_TOLERANCE_HZ 0, INSERT_VIP 0, PHASE 0.0" *) output FCLK_CLK1;
  (* X_INTERFACE_INFO = "xilinx.com:signal:reset:1.0 RST.FCLK_RESET0_N RST" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME RST.FCLK_RESET0_N, INSERT_VIP 0, POLARITY ACTIVE_LOW" *) output FCLK_RESET0_N;
  (* X_INTERFACE_INFO = "xilinx.com:display_processing_system7:fixedio:1.0 FIXED_IO DDR_VRN" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME FIXED_IO, CAN_DEBUG false" *) inout FIXED_IO_ddr_vrn;
  (* X_INTERFACE_INFO = "xilinx.com:display_processing_system7:fixedio:1.0 FIXED_IO DDR_VRP" *) inout FIXED_IO_ddr_vrp;
  (* X_INTERFACE_INFO = "xilinx.com:display_processing_system7:fixedio:1.0 FIXED_IO MIO" *) inout [53:0]FIXED_IO_mio;
  (* X_INTERFACE_INFO = "xilinx.com:display_processing_system7:fixedio:1.0 FIXED_IO PS_CLK" *) inout FIXED_IO_ps_clk;
  (* X_INTERFACE_INFO = "xilinx.com:display_processing_system7:fixedio:1.0 FIXED_IO PS_PORB" *) inout FIXED_IO_ps_porb;
  (* X_INTERFACE_INFO = "xilinx.com:display_processing_system7:fixedio:1.0 FIXED_IO PS_SRSTB" *) inout FIXED_IO_ps_srstb;
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.M_AXI_GP0_ACLK CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.M_AXI_GP0_ACLK, ASSOCIATED_BUSIF M_AXI_GP0, CLK_DOMAIN zynq_bd_M_AXI_GP0_ACLK_0, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, INSERT_VIP 0, PHASE 0.0" *) input M_AXI_GP0_ACLK;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME M_AXI_GP0, ADDR_WIDTH 32, ARUSER_WIDTH 0, AWUSER_WIDTH 0, BUSER_WIDTH 0, CLK_DOMAIN zynq_bd_M_AXI_GP0_ACLK_0, DATA_WIDTH 32, FREQ_HZ 100000000, HAS_BRESP 1, HAS_BURST 1, HAS_CACHE 1, HAS_LOCK 1, HAS_PROT 1, HAS_QOS 1, HAS_REGION 0, HAS_RRESP 1, HAS_WSTRB 1, ID_WIDTH 12, INSERT_VIP 0, MAX_BURST_LENGTH 16, NUM_READ_OUTSTANDING 8, NUM_READ_THREADS 4, NUM_WRITE_OUTSTANDING 8, NUM_WRITE_THREADS 4, PHASE 0.0, PROTOCOL AXI3, READ_WRITE_MODE READ_WRITE, RUSER_BITS_PER_BYTE 0, RUSER_WIDTH 0, SUPPORTS_NARROW_BURST 0, WUSER_BITS_PER_BYTE 0, WUSER_WIDTH 0" *) output [31:0]M_AXI_GP0_araddr;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [1:0]M_AXI_GP0_arburst;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [3:0]M_AXI_GP0_arcache;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [11:0]M_AXI_GP0_arid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [3:0]M_AXI_GP0_arlen;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [1:0]M_AXI_GP0_arlock;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [2:0]M_AXI_GP0_arprot;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [3:0]M_AXI_GP0_arqos;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) input M_AXI_GP0_arready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [2:0]M_AXI_GP0_arsize;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output M_AXI_GP0_arvalid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [31:0]M_AXI_GP0_awaddr;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [1:0]M_AXI_GP0_awburst;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [3:0]M_AXI_GP0_awcache;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [11:0]M_AXI_GP0_awid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [3:0]M_AXI_GP0_awlen;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [1:0]M_AXI_GP0_awlock;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [2:0]M_AXI_GP0_awprot;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [3:0]M_AXI_GP0_awqos;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) input M_AXI_GP0_awready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [2:0]M_AXI_GP0_awsize;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output M_AXI_GP0_awvalid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) input [11:0]M_AXI_GP0_bid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output M_AXI_GP0_bready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) input [1:0]M_AXI_GP0_bresp;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) input M_AXI_GP0_bvalid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) input [31:0]M_AXI_GP0_rdata;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) input [11:0]M_AXI_GP0_rid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) input M_AXI_GP0_rlast;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output M_AXI_GP0_rready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) input [1:0]M_AXI_GP0_rresp;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) input M_AXI_GP0_rvalid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [31:0]M_AXI_GP0_wdata;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [11:0]M_AXI_GP0_wid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output M_AXI_GP0_wlast;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) input M_AXI_GP0_wready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output [3:0]M_AXI_GP0_wstrb;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 M_AXI_GP0 " *) output M_AXI_GP0_wvalid;
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.S_AXI_HP0_ACLK CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.S_AXI_HP0_ACLK, ASSOCIATED_BUSIF S_AXI_HP0, CLK_DOMAIN zynq_bd_S_AXI_HP0_ACLK, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, INSERT_VIP 0, PHASE 0.0" *) input S_AXI_HP0_ACLK;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 ARADDR" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME S_AXI_HP0, ADDR_WIDTH 32, ARUSER_WIDTH 0, AWUSER_WIDTH 0, BUSER_WIDTH 0, CLK_DOMAIN zynq_bd_S_AXI_HP0_ACLK, DATA_WIDTH 64, FREQ_HZ 100000000, HAS_BRESP 1, HAS_BURST 1, HAS_CACHE 1, HAS_LOCK 1, HAS_PROT 1, HAS_QOS 1, HAS_REGION 0, HAS_RRESP 1, HAS_WSTRB 1, ID_WIDTH 6, INSERT_VIP 0, MAX_BURST_LENGTH 16, NUM_READ_OUTSTANDING 8, NUM_READ_THREADS 1, NUM_WRITE_OUTSTANDING 8, NUM_WRITE_THREADS 1, PHASE 0.0, PROTOCOL AXI3, READ_WRITE_MODE READ_WRITE, RUSER_BITS_PER_BYTE 0, RUSER_WIDTH 0, SUPPORTS_NARROW_BURST 1, WUSER_BITS_PER_BYTE 0, WUSER_WIDTH 0" *) input [31:0]S_AXI_HP0_araddr;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 ARBURST" *) input [1:0]S_AXI_HP0_arburst;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 ARCACHE" *) input [3:0]S_AXI_HP0_arcache;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 ARID" *) input [5:0]S_AXI_HP0_arid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 ARLEN" *) input [3:0]S_AXI_HP0_arlen;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 ARLOCK" *) input [1:0]S_AXI_HP0_arlock;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 ARPROT" *) input [2:0]S_AXI_HP0_arprot;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 ARQOS" *) input [3:0]S_AXI_HP0_arqos;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 ARREADY" *) output S_AXI_HP0_arready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 ARSIZE" *) input [2:0]S_AXI_HP0_arsize;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 ARVALID" *) input S_AXI_HP0_arvalid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 AWADDR" *) input [31:0]S_AXI_HP0_awaddr;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 AWBURST" *) input [1:0]S_AXI_HP0_awburst;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 AWCACHE" *) input [3:0]S_AXI_HP0_awcache;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 AWID" *) input [5:0]S_AXI_HP0_awid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 AWLEN" *) input [3:0]S_AXI_HP0_awlen;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 AWLOCK" *) input [1:0]S_AXI_HP0_awlock;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 AWPROT" *) input [2:0]S_AXI_HP0_awprot;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 AWQOS" *) input [3:0]S_AXI_HP0_awqos;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 AWREADY" *) output S_AXI_HP0_awready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 AWSIZE" *) input [2:0]S_AXI_HP0_awsize;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 AWVALID" *) input S_AXI_HP0_awvalid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 BID" *) output [5:0]S_AXI_HP0_bid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 BREADY" *) input S_AXI_HP0_bready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 BRESP" *) output [1:0]S_AXI_HP0_bresp;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 BVALID" *) output S_AXI_HP0_bvalid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 RDATA" *) output [63:0]S_AXI_HP0_rdata;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 RID" *) output [5:0]S_AXI_HP0_rid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 RLAST" *) output S_AXI_HP0_rlast;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 RREADY" *) input S_AXI_HP0_rready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 RRESP" *) output [1:0]S_AXI_HP0_rresp;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 RVALID" *) output S_AXI_HP0_rvalid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 WDATA" *) input [63:0]S_AXI_HP0_wdata;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 WID" *) input [5:0]S_AXI_HP0_wid;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 WLAST" *) input S_AXI_HP0_wlast;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 WREADY" *) output S_AXI_HP0_wready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 WSTRB" *) input [7:0]S_AXI_HP0_wstrb;
  (* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_HP0 WVALID" *) input S_AXI_HP0_wvalid;

  wire M_AXI_GP0_ACLK_0_1;
  wire [31:0]S_AXI_HP0_0_1_ARADDR;
  wire [1:0]S_AXI_HP0_0_1_ARBURST;
  wire [3:0]S_AXI_HP0_0_1_ARCACHE;
  wire [5:0]S_AXI_HP0_0_1_ARID;
  wire [3:0]S_AXI_HP0_0_1_ARLEN;
  wire [1:0]S_AXI_HP0_0_1_ARLOCK;
  wire [2:0]S_AXI_HP0_0_1_ARPROT;
  wire [3:0]S_AXI_HP0_0_1_ARQOS;
  wire S_AXI_HP0_0_1_ARREADY;
  wire [2:0]S_AXI_HP0_0_1_ARSIZE;
  wire S_AXI_HP0_0_1_ARVALID;
  wire [31:0]S_AXI_HP0_0_1_AWADDR;
  wire [1:0]S_AXI_HP0_0_1_AWBURST;
  wire [3:0]S_AXI_HP0_0_1_AWCACHE;
  wire [5:0]S_AXI_HP0_0_1_AWID;
  wire [3:0]S_AXI_HP0_0_1_AWLEN;
  wire [1:0]S_AXI_HP0_0_1_AWLOCK;
  wire [2:0]S_AXI_HP0_0_1_AWPROT;
  wire [3:0]S_AXI_HP0_0_1_AWQOS;
  wire S_AXI_HP0_0_1_AWREADY;
  wire [2:0]S_AXI_HP0_0_1_AWSIZE;
  wire S_AXI_HP0_0_1_AWVALID;
  wire [5:0]S_AXI_HP0_0_1_BID;
  wire S_AXI_HP0_0_1_BREADY;
  wire [1:0]S_AXI_HP0_0_1_BRESP;
  wire S_AXI_HP0_0_1_BVALID;
  wire [63:0]S_AXI_HP0_0_1_RDATA;
  wire [5:0]S_AXI_HP0_0_1_RID;
  wire S_AXI_HP0_0_1_RLAST;
  wire S_AXI_HP0_0_1_RREADY;
  wire [1:0]S_AXI_HP0_0_1_RRESP;
  wire S_AXI_HP0_0_1_RVALID;
  wire [63:0]S_AXI_HP0_0_1_WDATA;
  wire [5:0]S_AXI_HP0_0_1_WID;
  wire S_AXI_HP0_0_1_WLAST;
  wire S_AXI_HP0_0_1_WREADY;
  wire [7:0]S_AXI_HP0_0_1_WSTRB;
  wire S_AXI_HP0_0_1_WVALID;
  wire S_AXI_HP0_ACLK_1;
  wire [14:0]ps7_DDR_ADDR;
  wire [2:0]ps7_DDR_BA;
  wire ps7_DDR_CAS_N;
  wire ps7_DDR_CKE;
  wire ps7_DDR_CK_N;
  wire ps7_DDR_CK_P;
  wire ps7_DDR_CS_N;
  wire [3:0]ps7_DDR_DM;
  wire [31:0]ps7_DDR_DQ;
  wire [3:0]ps7_DDR_DQS_N;
  wire [3:0]ps7_DDR_DQS_P;
  wire ps7_DDR_ODT;
  wire ps7_DDR_RAS_N;
  wire ps7_DDR_RESET_N;
  wire ps7_DDR_WE_N;
  wire ps7_FCLK_CLK0;
  wire ps7_FCLK_CLK1;
  wire ps7_FCLK_RESET0_N;
  wire ps7_FIXED_IO_DDR_VRN;
  wire ps7_FIXED_IO_DDR_VRP;
  wire [53:0]ps7_FIXED_IO_MIO;
  wire ps7_FIXED_IO_PS_CLK;
  wire ps7_FIXED_IO_PS_PORB;
  wire ps7_FIXED_IO_PS_SRSTB;
  wire [31:0]ps7_M_AXI_GP0_ARADDR;
  wire [1:0]ps7_M_AXI_GP0_ARBURST;
  wire [3:0]ps7_M_AXI_GP0_ARCACHE;
  wire [11:0]ps7_M_AXI_GP0_ARID;
  wire [3:0]ps7_M_AXI_GP0_ARLEN;
  wire [1:0]ps7_M_AXI_GP0_ARLOCK;
  wire [2:0]ps7_M_AXI_GP0_ARPROT;
  wire [3:0]ps7_M_AXI_GP0_ARQOS;
  wire ps7_M_AXI_GP0_ARREADY;
  wire [2:0]ps7_M_AXI_GP0_ARSIZE;
  wire ps7_M_AXI_GP0_ARVALID;
  wire [31:0]ps7_M_AXI_GP0_AWADDR;
  wire [1:0]ps7_M_AXI_GP0_AWBURST;
  wire [3:0]ps7_M_AXI_GP0_AWCACHE;
  wire [11:0]ps7_M_AXI_GP0_AWID;
  wire [3:0]ps7_M_AXI_GP0_AWLEN;
  wire [1:0]ps7_M_AXI_GP0_AWLOCK;
  wire [2:0]ps7_M_AXI_GP0_AWPROT;
  wire [3:0]ps7_M_AXI_GP0_AWQOS;
  wire ps7_M_AXI_GP0_AWREADY;
  wire [2:0]ps7_M_AXI_GP0_AWSIZE;
  wire ps7_M_AXI_GP0_AWVALID;
  wire [11:0]ps7_M_AXI_GP0_BID;
  wire ps7_M_AXI_GP0_BREADY;
  wire [1:0]ps7_M_AXI_GP0_BRESP;
  wire ps7_M_AXI_GP0_BVALID;
  wire [31:0]ps7_M_AXI_GP0_RDATA;
  wire [11:0]ps7_M_AXI_GP0_RID;
  wire ps7_M_AXI_GP0_RLAST;
  wire ps7_M_AXI_GP0_RREADY;
  wire [1:0]ps7_M_AXI_GP0_RRESP;
  wire ps7_M_AXI_GP0_RVALID;
  wire [31:0]ps7_M_AXI_GP0_WDATA;
  wire [11:0]ps7_M_AXI_GP0_WID;
  wire ps7_M_AXI_GP0_WLAST;
  wire ps7_M_AXI_GP0_WREADY;
  wire [3:0]ps7_M_AXI_GP0_WSTRB;
  wire ps7_M_AXI_GP0_WVALID;

  assign FCLK_CLK0 = ps7_FCLK_CLK0;
  assign FCLK_CLK1 = ps7_FCLK_CLK1;
  assign FCLK_RESET0_N = ps7_FCLK_RESET0_N;
  assign M_AXI_GP0_ACLK_0_1 = M_AXI_GP0_ACLK;
  assign M_AXI_GP0_araddr[31:0] = ps7_M_AXI_GP0_ARADDR;
  assign M_AXI_GP0_arburst[1:0] = ps7_M_AXI_GP0_ARBURST;
  assign M_AXI_GP0_arcache[3:0] = ps7_M_AXI_GP0_ARCACHE;
  assign M_AXI_GP0_arid[11:0] = ps7_M_AXI_GP0_ARID;
  assign M_AXI_GP0_arlen[3:0] = ps7_M_AXI_GP0_ARLEN;
  assign M_AXI_GP0_arlock[1:0] = ps7_M_AXI_GP0_ARLOCK;
  assign M_AXI_GP0_arprot[2:0] = ps7_M_AXI_GP0_ARPROT;
  assign M_AXI_GP0_arqos[3:0] = ps7_M_AXI_GP0_ARQOS;
  assign M_AXI_GP0_arsize[2:0] = ps7_M_AXI_GP0_ARSIZE;
  assign M_AXI_GP0_arvalid = ps7_M_AXI_GP0_ARVALID;
  assign M_AXI_GP0_awaddr[31:0] = ps7_M_AXI_GP0_AWADDR;
  assign M_AXI_GP0_awburst[1:0] = ps7_M_AXI_GP0_AWBURST;
  assign M_AXI_GP0_awcache[3:0] = ps7_M_AXI_GP0_AWCACHE;
  assign M_AXI_GP0_awid[11:0] = ps7_M_AXI_GP0_AWID;
  assign M_AXI_GP0_awlen[3:0] = ps7_M_AXI_GP0_AWLEN;
  assign M_AXI_GP0_awlock[1:0] = ps7_M_AXI_GP0_AWLOCK;
  assign M_AXI_GP0_awprot[2:0] = ps7_M_AXI_GP0_AWPROT;
  assign M_AXI_GP0_awqos[3:0] = ps7_M_AXI_GP0_AWQOS;
  assign M_AXI_GP0_awsize[2:0] = ps7_M_AXI_GP0_AWSIZE;
  assign M_AXI_GP0_awvalid = ps7_M_AXI_GP0_AWVALID;
  assign M_AXI_GP0_bready = ps7_M_AXI_GP0_BREADY;
  assign M_AXI_GP0_rready = ps7_M_AXI_GP0_RREADY;
  assign M_AXI_GP0_wdata[31:0] = ps7_M_AXI_GP0_WDATA;
  assign M_AXI_GP0_wid[11:0] = ps7_M_AXI_GP0_WID;
  assign M_AXI_GP0_wlast = ps7_M_AXI_GP0_WLAST;
  assign M_AXI_GP0_wstrb[3:0] = ps7_M_AXI_GP0_WSTRB;
  assign M_AXI_GP0_wvalid = ps7_M_AXI_GP0_WVALID;
  assign S_AXI_HP0_0_1_ARADDR = S_AXI_HP0_araddr[31:0];
  assign S_AXI_HP0_0_1_ARBURST = S_AXI_HP0_arburst[1:0];
  assign S_AXI_HP0_0_1_ARCACHE = S_AXI_HP0_arcache[3:0];
  assign S_AXI_HP0_0_1_ARID = S_AXI_HP0_arid[5:0];
  assign S_AXI_HP0_0_1_ARLEN = S_AXI_HP0_arlen[3:0];
  assign S_AXI_HP0_0_1_ARLOCK = S_AXI_HP0_arlock[1:0];
  assign S_AXI_HP0_0_1_ARPROT = S_AXI_HP0_arprot[2:0];
  assign S_AXI_HP0_0_1_ARQOS = S_AXI_HP0_arqos[3:0];
  assign S_AXI_HP0_0_1_ARSIZE = S_AXI_HP0_arsize[2:0];
  assign S_AXI_HP0_0_1_ARVALID = S_AXI_HP0_arvalid;
  assign S_AXI_HP0_0_1_AWADDR = S_AXI_HP0_awaddr[31:0];
  assign S_AXI_HP0_0_1_AWBURST = S_AXI_HP0_awburst[1:0];
  assign S_AXI_HP0_0_1_AWCACHE = S_AXI_HP0_awcache[3:0];
  assign S_AXI_HP0_0_1_AWID = S_AXI_HP0_awid[5:0];
  assign S_AXI_HP0_0_1_AWLEN = S_AXI_HP0_awlen[3:0];
  assign S_AXI_HP0_0_1_AWLOCK = S_AXI_HP0_awlock[1:0];
  assign S_AXI_HP0_0_1_AWPROT = S_AXI_HP0_awprot[2:0];
  assign S_AXI_HP0_0_1_AWQOS = S_AXI_HP0_awqos[3:0];
  assign S_AXI_HP0_0_1_AWSIZE = S_AXI_HP0_awsize[2:0];
  assign S_AXI_HP0_0_1_AWVALID = S_AXI_HP0_awvalid;
  assign S_AXI_HP0_0_1_BREADY = S_AXI_HP0_bready;
  assign S_AXI_HP0_0_1_RREADY = S_AXI_HP0_rready;
  assign S_AXI_HP0_0_1_WDATA = S_AXI_HP0_wdata[63:0];
  assign S_AXI_HP0_0_1_WID = S_AXI_HP0_wid[5:0];
  assign S_AXI_HP0_0_1_WLAST = S_AXI_HP0_wlast;
  assign S_AXI_HP0_0_1_WSTRB = S_AXI_HP0_wstrb[7:0];
  assign S_AXI_HP0_0_1_WVALID = S_AXI_HP0_wvalid;
  assign S_AXI_HP0_ACLK_1 = S_AXI_HP0_ACLK;
  assign S_AXI_HP0_arready = S_AXI_HP0_0_1_ARREADY;
  assign S_AXI_HP0_awready = S_AXI_HP0_0_1_AWREADY;
  assign S_AXI_HP0_bid[5:0] = S_AXI_HP0_0_1_BID;
  assign S_AXI_HP0_bresp[1:0] = S_AXI_HP0_0_1_BRESP;
  assign S_AXI_HP0_bvalid = S_AXI_HP0_0_1_BVALID;
  assign S_AXI_HP0_rdata[63:0] = S_AXI_HP0_0_1_RDATA;
  assign S_AXI_HP0_rid[5:0] = S_AXI_HP0_0_1_RID;
  assign S_AXI_HP0_rlast = S_AXI_HP0_0_1_RLAST;
  assign S_AXI_HP0_rresp[1:0] = S_AXI_HP0_0_1_RRESP;
  assign S_AXI_HP0_rvalid = S_AXI_HP0_0_1_RVALID;
  assign S_AXI_HP0_wready = S_AXI_HP0_0_1_WREADY;
  assign ps7_M_AXI_GP0_ARREADY = M_AXI_GP0_arready;
  assign ps7_M_AXI_GP0_AWREADY = M_AXI_GP0_awready;
  assign ps7_M_AXI_GP0_BID = M_AXI_GP0_bid[11:0];
  assign ps7_M_AXI_GP0_BRESP = M_AXI_GP0_bresp[1:0];
  assign ps7_M_AXI_GP0_BVALID = M_AXI_GP0_bvalid;
  assign ps7_M_AXI_GP0_RDATA = M_AXI_GP0_rdata[31:0];
  assign ps7_M_AXI_GP0_RID = M_AXI_GP0_rid[11:0];
  assign ps7_M_AXI_GP0_RLAST = M_AXI_GP0_rlast;
  assign ps7_M_AXI_GP0_RRESP = M_AXI_GP0_rresp[1:0];
  assign ps7_M_AXI_GP0_RVALID = M_AXI_GP0_rvalid;
  assign ps7_M_AXI_GP0_WREADY = M_AXI_GP0_wready;
  zynq_bd_ps7_0 ps7
       (.DDR_Addr(DDR_addr[14:0]),
        .DDR_BankAddr(DDR_ba[2:0]),
        .DDR_CAS_n(DDR_cas_n),
        .DDR_CKE(DDR_cke),
        .DDR_CS_n(DDR_cs_n),
        .DDR_Clk(DDR_ck_p),
        .DDR_Clk_n(DDR_ck_n),
        .DDR_DM(DDR_dm[3:0]),
        .DDR_DQ(DDR_dq[31:0]),
        .DDR_DQS(DDR_dqs_p[3:0]),
        .DDR_DQS_n(DDR_dqs_n[3:0]),
        .DDR_DRSTB(DDR_reset_n),
        .DDR_ODT(DDR_odt),
        .DDR_RAS_n(DDR_ras_n),
        .DDR_VRN(FIXED_IO_ddr_vrn),
        .DDR_VRP(FIXED_IO_ddr_vrp),
        .DDR_WEB(DDR_we_n),
        .FCLK_CLK0(ps7_FCLK_CLK0),
        .FCLK_CLK1(ps7_FCLK_CLK1),
        .FCLK_RESET0_N(ps7_FCLK_RESET0_N),
        .MIO(FIXED_IO_mio[53:0]),
        .M_AXI_GP0_ACLK(M_AXI_GP0_ACLK_0_1),
        .M_AXI_GP0_ARADDR(ps7_M_AXI_GP0_ARADDR),
        .M_AXI_GP0_ARBURST(ps7_M_AXI_GP0_ARBURST),
        .M_AXI_GP0_ARCACHE(ps7_M_AXI_GP0_ARCACHE),
        .M_AXI_GP0_ARID(ps7_M_AXI_GP0_ARID),
        .M_AXI_GP0_ARLEN(ps7_M_AXI_GP0_ARLEN),
        .M_AXI_GP0_ARLOCK(ps7_M_AXI_GP0_ARLOCK),
        .M_AXI_GP0_ARPROT(ps7_M_AXI_GP0_ARPROT),
        .M_AXI_GP0_ARQOS(ps7_M_AXI_GP0_ARQOS),
        .M_AXI_GP0_ARREADY(ps7_M_AXI_GP0_ARREADY),
        .M_AXI_GP0_ARSIZE(ps7_M_AXI_GP0_ARSIZE),
        .M_AXI_GP0_ARVALID(ps7_M_AXI_GP0_ARVALID),
        .M_AXI_GP0_AWADDR(ps7_M_AXI_GP0_AWADDR),
        .M_AXI_GP0_AWBURST(ps7_M_AXI_GP0_AWBURST),
        .M_AXI_GP0_AWCACHE(ps7_M_AXI_GP0_AWCACHE),
        .M_AXI_GP0_AWID(ps7_M_AXI_GP0_AWID),
        .M_AXI_GP0_AWLEN(ps7_M_AXI_GP0_AWLEN),
        .M_AXI_GP0_AWLOCK(ps7_M_AXI_GP0_AWLOCK),
        .M_AXI_GP0_AWPROT(ps7_M_AXI_GP0_AWPROT),
        .M_AXI_GP0_AWQOS(ps7_M_AXI_GP0_AWQOS),
        .M_AXI_GP0_AWREADY(ps7_M_AXI_GP0_AWREADY),
        .M_AXI_GP0_AWSIZE(ps7_M_AXI_GP0_AWSIZE),
        .M_AXI_GP0_AWVALID(ps7_M_AXI_GP0_AWVALID),
        .M_AXI_GP0_BID(ps7_M_AXI_GP0_BID),
        .M_AXI_GP0_BREADY(ps7_M_AXI_GP0_BREADY),
        .M_AXI_GP0_BRESP(ps7_M_AXI_GP0_BRESP),
        .M_AXI_GP0_BVALID(ps7_M_AXI_GP0_BVALID),
        .M_AXI_GP0_RDATA(ps7_M_AXI_GP0_RDATA),
        .M_AXI_GP0_RID(ps7_M_AXI_GP0_RID),
        .M_AXI_GP0_RLAST(ps7_M_AXI_GP0_RLAST),
        .M_AXI_GP0_RREADY(ps7_M_AXI_GP0_RREADY),
        .M_AXI_GP0_RRESP(ps7_M_AXI_GP0_RRESP),
        .M_AXI_GP0_RVALID(ps7_M_AXI_GP0_RVALID),
        .M_AXI_GP0_WDATA(ps7_M_AXI_GP0_WDATA),
        .M_AXI_GP0_WID(ps7_M_AXI_GP0_WID),
        .M_AXI_GP0_WLAST(ps7_M_AXI_GP0_WLAST),
        .M_AXI_GP0_WREADY(ps7_M_AXI_GP0_WREADY),
        .M_AXI_GP0_WSTRB(ps7_M_AXI_GP0_WSTRB),
        .M_AXI_GP0_WVALID(ps7_M_AXI_GP0_WVALID),
        .PS_CLK(FIXED_IO_ps_clk),
        .PS_PORB(FIXED_IO_ps_porb),
        .PS_SRSTB(FIXED_IO_ps_srstb),
        .S_AXI_HP0_ACLK(S_AXI_HP0_ACLK_1),
        .S_AXI_HP0_ARADDR(S_AXI_HP0_0_1_ARADDR),
        .S_AXI_HP0_ARBURST(S_AXI_HP0_0_1_ARBURST),
        .S_AXI_HP0_ARCACHE(S_AXI_HP0_0_1_ARCACHE),
        .S_AXI_HP0_ARID(S_AXI_HP0_0_1_ARID),
        .S_AXI_HP0_ARLEN(S_AXI_HP0_0_1_ARLEN),
        .S_AXI_HP0_ARLOCK(S_AXI_HP0_0_1_ARLOCK),
        .S_AXI_HP0_ARPROT(S_AXI_HP0_0_1_ARPROT),
        .S_AXI_HP0_ARQOS(S_AXI_HP0_0_1_ARQOS),
        .S_AXI_HP0_ARREADY(S_AXI_HP0_0_1_ARREADY),
        .S_AXI_HP0_ARSIZE(S_AXI_HP0_0_1_ARSIZE),
        .S_AXI_HP0_ARVALID(S_AXI_HP0_0_1_ARVALID),
        .S_AXI_HP0_AWADDR(S_AXI_HP0_0_1_AWADDR),
        .S_AXI_HP0_AWBURST(S_AXI_HP0_0_1_AWBURST),
        .S_AXI_HP0_AWCACHE(S_AXI_HP0_0_1_AWCACHE),
        .S_AXI_HP0_AWID(S_AXI_HP0_0_1_AWID),
        .S_AXI_HP0_AWLEN(S_AXI_HP0_0_1_AWLEN),
        .S_AXI_HP0_AWLOCK(S_AXI_HP0_0_1_AWLOCK),
        .S_AXI_HP0_AWPROT(S_AXI_HP0_0_1_AWPROT),
        .S_AXI_HP0_AWQOS(S_AXI_HP0_0_1_AWQOS),
        .S_AXI_HP0_AWREADY(S_AXI_HP0_0_1_AWREADY),
        .S_AXI_HP0_AWSIZE(S_AXI_HP0_0_1_AWSIZE),
        .S_AXI_HP0_AWVALID(S_AXI_HP0_0_1_AWVALID),
        .S_AXI_HP0_BID(S_AXI_HP0_0_1_BID),
        .S_AXI_HP0_BREADY(S_AXI_HP0_0_1_BREADY),
        .S_AXI_HP0_BRESP(S_AXI_HP0_0_1_BRESP),
        .S_AXI_HP0_BVALID(S_AXI_HP0_0_1_BVALID),
        .S_AXI_HP0_RDATA(S_AXI_HP0_0_1_RDATA),
        .S_AXI_HP0_RDISSUECAP1_EN(1'b0),
        .S_AXI_HP0_RID(S_AXI_HP0_0_1_RID),
        .S_AXI_HP0_RLAST(S_AXI_HP0_0_1_RLAST),
        .S_AXI_HP0_RREADY(S_AXI_HP0_0_1_RREADY),
        .S_AXI_HP0_RRESP(S_AXI_HP0_0_1_RRESP),
        .S_AXI_HP0_RVALID(S_AXI_HP0_0_1_RVALID),
        .S_AXI_HP0_WDATA(S_AXI_HP0_0_1_WDATA),
        .S_AXI_HP0_WID(S_AXI_HP0_0_1_WID),
        .S_AXI_HP0_WLAST(S_AXI_HP0_0_1_WLAST),
        .S_AXI_HP0_WREADY(S_AXI_HP0_0_1_WREADY),
        .S_AXI_HP0_WRISSUECAP1_EN(1'b0),
        .S_AXI_HP0_WSTRB(S_AXI_HP0_0_1_WSTRB),
        .S_AXI_HP0_WVALID(S_AXI_HP0_0_1_WVALID),
        .USB0_VBUS_PWRFAULT(1'b0));
endmodule
