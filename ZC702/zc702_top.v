//----------------------------------------------------------------------------
// zc702_top.v — ZC702 top-level (Test 3 build)
//
// Adds:
//  - GP0 master ports from BD wrapper
//  - zc702_sysctrl AXI-Lite slave at 0x40000000
//  - LED mux: ARM (sysctrl_led) or VexRiscv (soc_base.led)
//  - Pushbutton input pins, fed both to soc_base.pushbutton and sysctrl.pb_in
//----------------------------------------------------------------------------
module zc702_top (
   inout  [14:0] DDR_addr,
   inout  [2:0]  DDR_ba,
   inout         DDR_cas_n,
   inout         DDR_ck_n,
   inout         DDR_ck_p,
   inout         DDR_cke,
   inout         DDR_cs_n,
   inout  [3:0]  DDR_dm,
   inout  [31:0] DDR_dq,
   inout  [3:0]  DDR_dqs_n,
   inout  [3:0]  DDR_dqs_p,
   inout         DDR_odt,
   inout         DDR_ras_n,
   inout         DDR_reset_n,
   inout         DDR_we_n,
   inout         FIXED_IO_ddr_vrn,
   inout         FIXED_IO_ddr_vrp,
   inout  [53:0] FIXED_IO_mio,
   inout         FIXED_IO_ps_clk,
   inout         FIXED_IO_ps_porb,
   inout         FIXED_IO_ps_srstb,
   output [3:0]  led,
   input  [1:0]  pushbutton_pl   // SW13, SW14
);

   wire        fclk_clk0;
   wire        fclk_clk1;
   wire        fclk_reset0_n;

   // ========================================================================
   // S_AXI_HP0 — soc_base SDRAM master to PS DDR (existing path)
   // ========================================================================
   wire [31:0] hp0_araddr;
   wire [1:0]  hp0_arburst;
   wire [3:0]  hp0_arcache;
   wire [5:0]  hp0_arid;
   wire [3:0]  hp0_arlen;
   wire [1:0]  hp0_arlock;
   wire [2:0]  hp0_arprot;
   wire [3:0]  hp0_arqos;
   wire        hp0_arready;
   wire [2:0]  hp0_arsize;
   wire        hp0_arvalid;
   wire [31:0] hp0_awaddr;
   wire [1:0]  hp0_awburst;
   wire [3:0]  hp0_awcache;
   wire [5:0]  hp0_awid;
   wire [3:0]  hp0_awlen;
   wire [1:0]  hp0_awlock;
   wire [2:0]  hp0_awprot;
   wire [3:0]  hp0_awqos;
   wire        hp0_awready;
   wire [2:0]  hp0_awsize;
   wire        hp0_awvalid;
   wire        hp0_bready;
   wire [1:0]  hp0_bresp;
   wire [5:0]  hp0_bid;
   wire        hp0_bvalid;
   wire [63:0] hp0_rdata;
   wire [5:0]  hp0_rid;
   wire        hp0_rlast;
   wire        hp0_rready;
   wire [1:0]  hp0_rresp;
   wire        hp0_rvalid;
   wire [63:0] hp0_wdata;
   wire [5:0]  hp0_wid;
   wire        hp0_wlast;
   wire        hp0_wready;
   wire [7:0]  hp0_wstrb;
   wire        hp0_wvalid;

   // ========================================================================
   // M_AXI_GP0 — ARM master, drives sysctrl AXI-Lite (NEW for Test 3)
   // 32-bit data, 32-bit addr.
   // ========================================================================
   wire [31:0] gp0_araddr;
   wire [1:0]  gp0_arburst;
   wire [3:0]  gp0_arcache;
   wire [11:0] gp0_arid;
   wire [3:0]  gp0_arlen;
   wire [1:0]  gp0_arlock;
   wire [2:0]  gp0_arprot;
   wire [3:0]  gp0_arqos;
   wire        gp0_arready;
   wire [2:0]  gp0_arsize;
   wire        gp0_arvalid;
   wire [31:0] gp0_awaddr;
   wire [1:0]  gp0_awburst;
   wire [3:0]  gp0_awcache;
   wire [11:0] gp0_awid;
   wire [3:0]  gp0_awlen;
   wire [1:0]  gp0_awlock;
   wire [2:0]  gp0_awprot;
   wire [3:0]  gp0_awqos;
   wire        gp0_awready;
   wire [2:0]  gp0_awsize;
   wire        gp0_awvalid;
   wire [11:0] gp0_bid;
   wire        gp0_bready;
   wire [1:0]  gp0_bresp;
   wire        gp0_bvalid;
   wire [31:0] gp0_rdata;
   wire [11:0] gp0_rid;
   wire        gp0_rlast;
   wire        gp0_rready;
   wire [1:0]  gp0_rresp;
   wire        gp0_rvalid;
   wire [31:0] gp0_wdata;
   wire [11:0] gp0_wid;
   wire        gp0_wlast;
   wire        gp0_wready;
   wire [3:0]  gp0_wstrb;
   wire        gp0_wvalid;

   // ========================================================================
   // soc_base SDRAM signals (existing)
   // ========================================================================
   wire [31:0] sdram_araddr;
   wire [1:0]  sdram_arburst;
   wire [7:0]  sdram_arlen;
   wire        sdram_arready;
   wire [2:0]  sdram_arsize;
   wire        sdram_arvalid;
   wire [31:0] sdram_awaddr;
   wire [1:0]  sdram_awburst;
   wire [7:0]  sdram_awlen;
   wire        sdram_awready;
   wire [2:0]  sdram_awsize;
   wire        sdram_awvalid;
   wire        sdram_bready;
   wire [1:0]  sdram_bresp;
   wire        sdram_bvalid;
   wire [63:0] sdram_rdata;
   wire        sdram_rlast;
   wire        sdram_rready;
   wire [1:0]  sdram_rresp;
   wire        sdram_rvalid;
   wire [63:0] sdram_wdata;
   wire        sdram_wlast;
   wire        sdram_wready;
   wire [7:0]  sdram_wstrb;
   wire        sdram_wvalid;

   wire [19:0] apb_paddr;
   wire [15:0] apb_penable;
   wire        apb_pwrite;
   wire [31:0] apb_pwdata;

   // ========================================================================
   // sysctrl <-> top wires
   // ========================================================================
   wire [3:0] sysctrl_led_arm;
   wire       sysctrl_led_src_sel;
   wire       sysctrl_cpu_reset;     // unused in Test 3 (Test 4 wires it to soc_base)
   wire [3:0] sysctrl_pb;
   wire [3:0] soc_base_led;

   // ========================================================================
   // APB UART bridge wires
   // ========================================================================
   wire [31:0] gp0_araddr_s;   // sysctrl portion
   wire [31:0] gp0_araddr_b;   // bridge portion
   wire        gp0_arvalid_s, gp0_arready_s, gp0_rvalid_s, gp0_rready_s;
   wire        gp0_arvalid_b, gp0_arready_b, gp0_rvalid_b, gp0_rready_b;
   wire [31:0] gp0_rdata_s, gp0_rdata_b;
   wire [1:0]  gp0_rresp_s, gp0_rresp_b;
   wire        gp0_awvalid_s, gp0_awready_s, gp0_wvalid_s, gp0_wready_s;
   wire        gp0_awvalid_b, gp0_awready_b, gp0_wvalid_b, gp0_wready_b;
   wire        gp0_bvalid_s, gp0_bready_s, gp0_bvalid_b, gp0_bready_b;
   wire [1:0]  gp0_bresp_s, gp0_bresp_b;
   // APB snoop wires (bridge reads from soc_base outputs)
   wire        sel_bridge;  // 1=bridge, 0=sysctrl

   // ========================================================================
   // Block-design wrapper instance
   // ========================================================================
   zynq_bd_wrapper bd_inst (
      .DDR_addr          (DDR_addr),
      .DDR_ba            (DDR_ba),
      .DDR_cas_n         (DDR_cas_n),
      .DDR_ck_n          (DDR_ck_n),
      .DDR_ck_p          (DDR_ck_p),
      .DDR_cke           (DDR_cke),
      .DDR_cs_n          (DDR_cs_n),
      .DDR_dm            (DDR_dm),
      .DDR_dq            (DDR_dq),
      .DDR_dqs_n         (DDR_dqs_n),
      .DDR_dqs_p         (DDR_dqs_p),
      .DDR_odt           (DDR_odt),
      .DDR_ras_n         (DDR_ras_n),
      .DDR_reset_n       (DDR_reset_n),
      .DDR_we_n          (DDR_we_n),
      .FIXED_IO_ddr_vrn  (FIXED_IO_ddr_vrn),
      .FIXED_IO_ddr_vrp  (FIXED_IO_ddr_vrp),
      .FIXED_IO_mio      (FIXED_IO_mio),
      .FIXED_IO_ps_clk   (FIXED_IO_ps_clk),
      .FIXED_IO_ps_porb  (FIXED_IO_ps_porb),
      .FIXED_IO_ps_srstb (FIXED_IO_ps_srstb),

      // S_AXI_HP0 (existing)
      .S_AXI_HP0_ACLK    (fclk_clk0),
      .S_AXI_HP0_araddr  (hp0_araddr),
      .S_AXI_HP0_arburst (hp0_arburst),
      .S_AXI_HP0_arcache (hp0_arcache),
      .S_AXI_HP0_arid    (hp0_arid),
      .S_AXI_HP0_arlen   (hp0_arlen),
      .S_AXI_HP0_arlock  (hp0_arlock),
      .S_AXI_HP0_arprot  (hp0_arprot),
      .S_AXI_HP0_arqos   (hp0_arqos),
      .S_AXI_HP0_arready (hp0_arready),
      .S_AXI_HP0_arsize  (hp0_arsize),
      .S_AXI_HP0_arvalid (hp0_arvalid),
      .S_AXI_HP0_awaddr  (hp0_awaddr),
      .S_AXI_HP0_awburst (hp0_awburst),
      .S_AXI_HP0_awcache (hp0_awcache),
      .S_AXI_HP0_awid    (hp0_awid),
      .S_AXI_HP0_awlen   (hp0_awlen),
      .S_AXI_HP0_awlock  (hp0_awlock),
      .S_AXI_HP0_awprot  (hp0_awprot),
      .S_AXI_HP0_awqos   (hp0_awqos),
      .S_AXI_HP0_awready (hp0_awready),
      .S_AXI_HP0_awsize  (hp0_awsize),
      .S_AXI_HP0_awvalid (hp0_awvalid),
      .S_AXI_HP0_bready  (hp0_bready),
      .S_AXI_HP0_bresp   (hp0_bresp),
      .S_AXI_HP0_bid     (hp0_bid),
      .S_AXI_HP0_bvalid  (hp0_bvalid),
      .S_AXI_HP0_rdata   (hp0_rdata),
      .S_AXI_HP0_rid     (hp0_rid),
      .S_AXI_HP0_rlast   (hp0_rlast),
      .S_AXI_HP0_rready  (hp0_rready),
      .S_AXI_HP0_rresp   (hp0_rresp),
      .S_AXI_HP0_rvalid  (hp0_rvalid),
      .S_AXI_HP0_wdata   (hp0_wdata),
      .S_AXI_HP0_wid     (hp0_wid),
      .S_AXI_HP0_wlast   (hp0_wlast),
      .S_AXI_HP0_wready  (hp0_wready),
      .S_AXI_HP0_wstrb   (hp0_wstrb),
      .S_AXI_HP0_wvalid  (hp0_wvalid),

      // M_AXI_GP0 (NEW for Test 3)
      .M_AXI_GP0_ACLK    (fclk_clk0),
      .M_AXI_GP0_araddr  (gp0_araddr),
      .M_AXI_GP0_arburst (gp0_arburst),
      .M_AXI_GP0_arcache (gp0_arcache),
      .M_AXI_GP0_arid    (gp0_arid),
      .M_AXI_GP0_arlen   (gp0_arlen),
      .M_AXI_GP0_arlock  (gp0_arlock),
      .M_AXI_GP0_arprot  (gp0_arprot),
      .M_AXI_GP0_arqos   (gp0_arqos),
      .M_AXI_GP0_arready (gp0_arready),
      .M_AXI_GP0_arsize  (gp0_arsize),
      .M_AXI_GP0_arvalid (gp0_arvalid),
      .M_AXI_GP0_awaddr  (gp0_awaddr),
      .M_AXI_GP0_awburst (gp0_awburst),
      .M_AXI_GP0_awcache (gp0_awcache),
      .M_AXI_GP0_awid    (gp0_awid),
      .M_AXI_GP0_awlen   (gp0_awlen),
      .M_AXI_GP0_awlock  (gp0_awlock),
      .M_AXI_GP0_awprot  (gp0_awprot),
      .M_AXI_GP0_awqos   (gp0_awqos),
      .M_AXI_GP0_awready (gp0_awready),
      .M_AXI_GP0_awsize  (gp0_awsize),
      .M_AXI_GP0_awvalid (gp0_awvalid),
      .M_AXI_GP0_bid     (gp0_bid),
      .M_AXI_GP0_bready  (gp0_bready),
      .M_AXI_GP0_bresp   (gp0_bresp),
      .M_AXI_GP0_bvalid  (gp0_bvalid),
      .M_AXI_GP0_rdata   (gp0_rdata),
      .M_AXI_GP0_rid     (gp0_rid),
      .M_AXI_GP0_rlast   (gp0_rlast),
      .M_AXI_GP0_rready  (gp0_rready),
      .M_AXI_GP0_rresp   (gp0_rresp),
      .M_AXI_GP0_rvalid  (gp0_rvalid),
      .M_AXI_GP0_wdata   (gp0_wdata),
      .M_AXI_GP0_wid     (gp0_wid),
      .M_AXI_GP0_wlast   (gp0_wlast),
      .M_AXI_GP0_wready  (gp0_wready),
      .M_AXI_GP0_wstrb   (gp0_wstrb),
      .M_AXI_GP0_wvalid  (gp0_wvalid),

      .FCLK_CLK0         (fclk_clk0),
      .FCLK_CLK1         (fclk_clk1),
      .FCLK_RESET0_N     (fclk_reset0_n)
   );

   // ========================================================================
   // SDRAM <-> HP0 wiring (unchanged)
   // ========================================================================
   assign hp0_araddr   = sdram_araddr;
   assign hp0_arburst  = sdram_arburst;
   assign hp0_arlen    = (sdram_arlen > 8'd15) ? 4'd15 : sdram_arlen[3:0];
   assign hp0_arsize   = sdram_arsize;
   assign hp0_arvalid  = sdram_arvalid;
   assign sdram_arready = hp0_arready;
   assign hp0_arid     = 6'b0;
   assign hp0_arlock   = 2'b0;
   assign hp0_arcache  = 4'b0011;
   assign hp0_arprot   = 3'b0;
   assign hp0_arqos    = 4'b0;

   assign hp0_awaddr   = sdram_awaddr;
   assign hp0_awburst  = sdram_awburst;
   assign hp0_awlen    = (sdram_awlen > 8'd15) ? 4'd15 : sdram_awlen[3:0];
   assign hp0_awsize   = sdram_awsize;
   assign hp0_awvalid  = sdram_awvalid;
   assign sdram_awready = hp0_awready;
   assign hp0_awid     = 6'b0;
   assign hp0_awlock   = 2'b0;
   assign hp0_awcache  = 4'b0011;
   assign hp0_awprot   = 3'b0;
   assign hp0_awqos    = 4'b0;

   assign hp0_wdata    = sdram_wdata;
   assign hp0_wstrb    = sdram_wstrb;
   assign hp0_wlast    = sdram_wlast;
   assign hp0_wvalid   = sdram_wvalid;
   assign sdram_wready = hp0_wready;
   assign hp0_wid      = 6'b0;

   assign sdram_bresp  = hp0_bresp;
   assign sdram_bvalid = hp0_bvalid;
   assign hp0_bready   = sdram_bready;

   assign sdram_rdata  = hp0_rdata;
   assign sdram_rresp  = hp0_rresp;
   assign sdram_rlast  = hp0_rlast;
   assign sdram_rvalid = hp0_rvalid;
   assign hp0_rready   = sdram_rready;

   // ========================================================================
   // sysctrl AXI-Lite slave instance (NEW)
   // GP0 is 32-bit. We pass the lower 6 bits of address (16 regs window).
   // ========================================================================
   zc702_sysctrl #(
      .C_S_AXI_ADDR_WIDTH (6),
      .C_S_AXI_DATA_WIDTH (32)
   ) sysctrl_inst (
      .s_axi_aclk      (fclk_clk0),
      .s_axi_aresetn   (fclk_reset0_n),
      .s_axi_awaddr    (gp0_awaddr[5:0]),
      .s_axi_awprot    (gp0_awprot),
      .s_axi_awvalid   (gp0_awvalid_s),
      .s_axi_awready   (gp0_awready_s),
      .s_axi_wdata     (gp0_wdata),
      .s_axi_wstrb     (gp0_wstrb),
      .s_axi_wvalid    (gp0_wvalid_s),
      .s_axi_wready    (gp0_wready_s),
      .s_axi_bresp     (gp0_bresp_s),
      .s_axi_bvalid    (gp0_bvalid_s),
      .s_axi_bready    (gp0_bready_s),
      .s_axi_araddr    (gp0_araddr[5:0]),
      .s_axi_arprot    (gp0_arprot),
      .s_axi_arvalid   (gp0_arvalid_s),
      .s_axi_arready   (gp0_arready_s),
      .s_axi_rdata     (gp0_rdata_s),
      .s_axi_rresp     (gp0_rresp_s),
      .s_axi_rvalid    (gp0_rvalid_s),
      .s_axi_rready    (gp0_rready_s),
      .led_arm_out     (sysctrl_led_arm),
      .led_src_sel_out (sysctrl_led_src_sel),
      .cpu_reset_out   (sysctrl_cpu_reset),
      .pb_in           (sysctrl_pb)
   );

   // GP0 is single-master, single-burst. Loop back unused signals.
   assign gp0_bid     = gp0_awid;
   assign gp0_rid     = gp0_arid;
   assign gp0_rlast   = 1'b1;

   // ========================================================================
   // Pushbuttons: ZC702 has only 2 PL pushbuttons (SW13, SW14).
   // Tie upper bits to 0 for the 4-bit interfaces.
   // ========================================================================
   wire [3:0] pb_padded = {2'b00, pushbutton_pl[1:0]};
   assign sysctrl_pb = pb_padded;

   // ========================================================================
   // LED mux: ARM (sysctrl_led_arm) when sel=0, VexRiscv (soc_base_led) when sel=1
   // ========================================================================
   assign led = sysctrl_led_src_sel ? soc_base_led : sysctrl_led_arm;

   // ========================================================================
   // soc_base instance — pushbutton fed live, led brought out internally
   // CPU reset NOT yet under software control (Test 4 will change this).
   // ========================================================================
   soc_base soc_base_inst (
      .clk_main        (fclk_clk0),
      .clk_x2_main     (fclk_clk1),
      .clk_camera      (1'b0),
      .clk_vga         (1'b0),
      .clk_reset       (fclk_reset0_n & ~sysctrl_cpu_reset),
      .SDRAM_clk       (fclk_clk0),
      .SDRAM_reset     (~fclk_reset0_n),
      .SDRAM_araddr    (sdram_araddr),
      .SDRAM_arburst   (sdram_arburst),
      .SDRAM_arlen     (sdram_arlen),
      .SDRAM_arready   (sdram_arready),
      .SDRAM_arsize    (sdram_arsize),
      .SDRAM_arvalid   (sdram_arvalid),
      .SDRAM_awaddr    (sdram_awaddr),
      .SDRAM_awburst   (sdram_awburst),
      .SDRAM_awlen     (sdram_awlen),
      .SDRAM_awready   (sdram_awready),
      .SDRAM_awsize    (sdram_awsize),
      .SDRAM_awvalid   (sdram_awvalid),
      .SDRAM_bready    (sdram_bready),
      .SDRAM_bresp     (sdram_bresp),
      .SDRAM_bvalid    (sdram_bvalid),
      .SDRAM_rdata     (sdram_rdata),
      .SDRAM_rlast     (sdram_rlast),
      .SDRAM_rready    (sdram_rready),
      .SDRAM_rresp     (sdram_rresp),
      .SDRAM_rvalid    (sdram_rvalid),
      .SDRAM_wdata     (sdram_wdata),
      .SDRAM_wlast     (sdram_wlast),
      .SDRAM_wready    (sdram_wready),
      .SDRAM_wstrb     (sdram_wstrb),
      .SDRAM_wvalid    (sdram_wvalid),
      .APB_PADDR_OUT   (apb_paddr),
      .APB_PENABLE_OUT (apb_penable),
      .APB_PREADY_IN   (1'b1),
      .APB_PWRITE_OUT  (apb_pwrite),
      .APB_PWDATA_OUT  (apb_pwdata),
      .APB_PRDATA_IN   (32'h0),
      .APB_PSLVERROR_IN(1'b0),
      .led             (soc_base_led),
      .pushbutton      (pb_padded),
      .UART_TXD        (),
      .UART_RXD        (1'b1),
      .VGA_HS_O        (),
      .VGA_VS_O        (),
      .VGA_R           (),
      .VGA_B           (),
      .VGA_G           (),
      .CAMERA_SCL      (),
      .CAMERA_VS       (1'b0),
      .CAMERA_PCLK     (1'b0),
      .CAMERA_D        (8'b0),
      .CAMERA_RESET    (),
      .CAMERA_SDR      (),
      .CAMERA_RS       (1'b0),
      .CAMERA_MCLK     (),
      .CAMERA_PWDN     ()
   );

   // ========================================================================
   // GP0 address decoder: 0x40000000=sysctrl, 0x40010000=APB UART bridge
   // ========================================================================
   assign sel_bridge = (gp0_araddr[16] == 1'b1) || (gp0_awaddr[16] == 1'b1);

   // Read channel mux
   assign gp0_arvalid_s = gp0_arvalid & ~sel_bridge;
   assign gp0_arvalid_b = gp0_arvalid &  sel_bridge;
   assign gp0_arready   = sel_bridge ? gp0_arready_b : gp0_arready_s;
   assign gp0_rdata     = sel_bridge ? gp0_rdata_b   : gp0_rdata_s;
   assign gp0_rresp     = sel_bridge ? gp0_rresp_b   : gp0_rresp_s;
   assign gp0_rvalid    = sel_bridge ? gp0_rvalid_b  : gp0_rvalid_s;
   assign gp0_rready_s  = gp0_rready & ~sel_bridge;
   assign gp0_rready_b  = gp0_rready &  sel_bridge;

   // Write channel mux
   assign gp0_awvalid_s = gp0_awvalid & ~sel_bridge;
   assign gp0_awvalid_b = gp0_awvalid &  sel_bridge;
   assign gp0_awready   = sel_bridge ? gp0_awready_b : gp0_awready_s;
   assign gp0_wvalid_s  = gp0_wvalid & ~sel_bridge;
   assign gp0_wvalid_b  = gp0_wvalid &  sel_bridge;
   assign gp0_wready    = sel_bridge ? gp0_wready_b  : gp0_wready_s;
   assign gp0_bvalid    = sel_bridge ? gp0_bvalid_b  : gp0_bvalid_s;
   assign gp0_bready_s  = gp0_bready & ~sel_bridge;
   assign gp0_bready_b  = gp0_bready &  sel_bridge;
   assign gp0_bresp     = sel_bridge ? gp0_bresp_b   : gp0_bresp_s;

   // APB UART bridge instance
   zc702_apb_uart_bridge #(
      .C_S_AXI_ADDR_WIDTH(8),
      .C_S_AXI_DATA_WIDTH(32)
   ) apb_uart_bridge_inst (
      .s_axi_aclk    (fclk_clk0),
      .s_axi_aresetn (fclk_reset0_n),
      .s_axi_awaddr  (gp0_awaddr[7:0]),
      .s_axi_awprot  (gp0_awprot),
      .s_axi_awvalid (gp0_awvalid_b),
      .s_axi_awready (gp0_awready_b),
      .s_axi_wdata   (gp0_wdata),
      .s_axi_wstrb   (gp0_wstrb),
      .s_axi_wvalid  (gp0_wvalid_b),
      .s_axi_wready  (gp0_wready_b),
      .s_axi_bresp   (gp0_bresp_b),
      .s_axi_bvalid  (gp0_bvalid_b),
      .s_axi_bready  (gp0_bready_b),
      .s_axi_araddr  (gp0_araddr[7:0]),
      .s_axi_arprot  (gp0_arprot),
      .s_axi_arvalid (gp0_arvalid_b),
      .s_axi_arready (gp0_arready_b),
      .s_axi_rdata   (gp0_rdata_b),
      .s_axi_rresp   (gp0_rresp_b),
      .s_axi_rvalid  (gp0_rvalid_b),
      .s_axi_rready  (gp0_rready_b),
      .apb_paddr     (apb_paddr),
      .apb_pwrite    (apb_pwrite),
      .apb_pwdata    (apb_pwdata),
      .apb_penable   (apb_penable)
   );

endmodule

