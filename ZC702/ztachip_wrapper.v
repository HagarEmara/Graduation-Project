//---------------------------------------------------------------------------
// Copyright [2014] [Ztachip Technologies Inc]
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//----------------------------------------------------------------------------
//
// Verilog wrapper for the VHDL ztachip entity.
// Provides clean AXI4 / AXI-Lite interfaces suitable for Vivado Block Design
// integration with the Zynq-7000 Processing System on the ZC702 board.
//
//  Interfaces:
//    1. AXI4 Master (M_AXI_DDR)  — 64-bit data, ztachip→DDR via Zynq S_AXI_HP
//    2. AXI-Lite Slave (S_AXI_CONTROL) — 32-bit, ARM→ztachip control registers
//    3. AXI4 Slave (S_AXI_SRAM) — 32-bit read-only, ARM→ztachip SRAM access
//
//----------------------------------------------------------------------------

module ztachip_wrapper (

   // -------------------------------------------------------
   // Clock and Reset
   // -------------------------------------------------------
   input  wire        clock_in,        // Main clock (100 MHz from FCLK_CLK0)
   input  wire        clock_x2_in,     // 2x clock  (200 MHz from FCLK_CLK1)
   input  wire        reset_in,        // Active-low reset (from FCLK_RESET0_N)

   // -------------------------------------------------------
   // AXI4 Master — DDR Data Path (connects to Zynq S_AXI_HP0)
   // 64-bit data width
   // -------------------------------------------------------

   // Read Address Channel
   output wire [31:0] m_axi_ddr_araddr,
   output wire [7:0]  m_axi_ddr_arlen,
   output wire [2:0]  m_axi_ddr_arsize,
   output wire [1:0]  m_axi_ddr_arburst,
   output wire [0:0]  m_axi_ddr_arid,
   output wire [0:0]  m_axi_ddr_arlock,
   output wire [3:0]  m_axi_ddr_arcache,
   output wire [2:0]  m_axi_ddr_arprot,
   output wire [3:0]  m_axi_ddr_arqos,
   output wire        m_axi_ddr_arvalid,
   input  wire        m_axi_ddr_arready,

   // Read Data Channel
   input  wire [63:0] m_axi_ddr_rdata,
   input  wire [1:0]  m_axi_ddr_rresp,
   input  wire        m_axi_ddr_rlast,
   input  wire        m_axi_ddr_rvalid,
   output wire        m_axi_ddr_rready,

   // Write Address Channel
   output wire [31:0] m_axi_ddr_awaddr,
   output wire [7:0]  m_axi_ddr_awlen,
   output wire [2:0]  m_axi_ddr_awsize,
   output wire [1:0]  m_axi_ddr_awburst,
   output wire [0:0]  m_axi_ddr_awid,
   output wire [0:0]  m_axi_ddr_awlock,
   output wire [3:0]  m_axi_ddr_awcache,
   output wire [2:0]  m_axi_ddr_awprot,
   output wire [3:0]  m_axi_ddr_awqos,
   output wire        m_axi_ddr_awvalid,
   input  wire        m_axi_ddr_awready,

   // Write Data Channel
   output wire [63:0] m_axi_ddr_wdata,
   output wire [7:0]  m_axi_ddr_wstrb,
   output wire        m_axi_ddr_wlast,
   output wire        m_axi_ddr_wvalid,
   input  wire        m_axi_ddr_wready,

   // Write Response Channel
   input  wire [1:0]  m_axi_ddr_bresp,
   input  wire        m_axi_ddr_bvalid,
   output wire        m_axi_ddr_bready,

   // -------------------------------------------------------
   // AXI-Lite Slave — Host Control (connects from Zynq M_AXI_GP0)
   // 32-bit data, 24-bit address (16M address space)
   // -------------------------------------------------------

   // Read Address Channel
   input  wire [23:0] s_axi_ctrl_araddr,
   input  wire        s_axi_ctrl_arvalid,
   output wire        s_axi_ctrl_arready,

   // Read Data Channel
   output wire [31:0] s_axi_ctrl_rdata,
   output wire [1:0]  s_axi_ctrl_rresp,
   output wire        s_axi_ctrl_rvalid,
   input  wire        s_axi_ctrl_rready,

   // Write Address Channel
   input  wire [23:0] s_axi_ctrl_awaddr,
   input  wire        s_axi_ctrl_awvalid,
   output wire        s_axi_ctrl_awready,

   // Write Data Channel
   input  wire [31:0] s_axi_ctrl_wdata,
   input  wire        s_axi_ctrl_wvalid,
   output wire        s_axi_ctrl_wready,
   input  wire [3:0]  s_axi_ctrl_wstrb,

   // Write Response Channel
   output wire [1:0]  s_axi_ctrl_bresp,
   output wire        s_axi_ctrl_bvalid,
   input  wire        s_axi_ctrl_bready,

   // -------------------------------------------------------
   // AXI4 Slave — SRAM Access (read-only, connects from Zynq M_AXI_GP0)
   // 32-bit data
   // -------------------------------------------------------

   // Read Address Channel
   input  wire [31:0] s_axi_sram_araddr,
   input  wire [7:0]  s_axi_sram_arlen,
   input  wire [2:0]  s_axi_sram_arsize,
   input  wire [1:0]  s_axi_sram_arburst,
   input  wire        s_axi_sram_arvalid,
   output wire        s_axi_sram_arready,

   // Read Data Channel
   output wire [31:0] s_axi_sram_rdata,
   output wire [1:0]  s_axi_sram_rresp,
   output wire        s_axi_sram_rlast,
   output wire        s_axi_sram_rvalid,
   input  wire        s_axi_sram_rready
);

   // -------------------------------------------------------
   // Internal wires for ztachip entity connections
   // -------------------------------------------------------

   // ztachip axi_arlen/awlen are 4-bit (unsigned), need to pad to 8-bit
   wire [3:0] zta_arlen;
   wire [3:0] zta_awlen;

   // ztachip axi_bresp is 1-bit, standard AXI is 2-bit
   wire       zta_bresp;

   // ztachip rlast output (directly from AXI-Lite, unused here)
   wire       zta_ctrl_rlast;

   // -------------------------------------------------------
   // Pad burst length from 4-bit to 8-bit AXI4
   // -------------------------------------------------------
   assign m_axi_ddr_arlen = {4'b0000, zta_arlen};
   assign m_axi_ddr_awlen = {4'b0000, zta_awlen};

   // Map 2-bit AXI bresp to 1-bit ztachip bresp (take bit 0)
   assign zta_bresp = m_axi_ddr_bresp[0];

   // -------------------------------------------------------
   // Instantiate the VHDL ztachip entity
   // -------------------------------------------------------

   ztachip #(
      .FPU_ENABLED(1)     // Enable FPU (boolean TRUE maps to 1 in mixed-language)
   ) ztachip_inst (
      .clock_in       (clock_in),
      .clock_x2_in    (clock_x2_in),
      .reset_in       (reset_in),

      .debug_in       (4'b0000),

      // --- AXI Master: Read Address Channel ---
      .axi_araddr_out (m_axi_ddr_araddr),
      .axi_arlen_out  (zta_arlen),           // 4-bit, padded above
      .axi_arvalid_out(m_axi_ddr_arvalid),
      .axi_arready_in (m_axi_ddr_arready),
      .axi_arburst_out(m_axi_ddr_arburst),
      .axi_arcache_out(m_axi_ddr_arcache),
      .axi_arid_out   (m_axi_ddr_arid),
      .axi_arlock_out (m_axi_ddr_arlock),
      .axi_arprot_out (m_axi_ddr_arprot),
      .axi_arqos_out  (m_axi_ddr_arqos),
      .axi_arsize_out (m_axi_ddr_arsize),

      // --- AXI Master: Read Data Channel ---
      .axi_rdata_in   (m_axi_ddr_rdata),
      .axi_rvalid_in  (m_axi_ddr_rvalid),
      .axi_rlast_in   (m_axi_ddr_rlast),
      .axi_rready_out (m_axi_ddr_rready),

      // --- AXI Master: Write Address Channel ---
      .axi_awaddr_out (m_axi_ddr_awaddr),
      .axi_awlen_out  (zta_awlen),           // 4-bit, padded above
      .axi_awvalid_out(m_axi_ddr_awvalid),
      .axi_awready_in (m_axi_ddr_awready),
      .axi_awburst_out(m_axi_ddr_awburst),
      .axi_awcache_out(m_axi_ddr_awcache),
      .axi_awid_out   (m_axi_ddr_awid),
      .axi_awlock_out (m_axi_ddr_awlock),
      .axi_awprot_out (m_axi_ddr_awprot),
      .axi_awqos_out  (m_axi_ddr_awqos),
      .axi_awsize_out (m_axi_ddr_awsize),

      // --- AXI Master: Write Data Channel ---
      .axi_waddr_out  (),                    // Non-standard, leave unconnected
      .axi_wdata_out  (m_axi_ddr_wdata),
      .axi_wbe_out    (m_axi_ddr_wstrb),
      .axi_wlast_out  (m_axi_ddr_wlast),
      .axi_wvalid_out (m_axi_ddr_wvalid),
      .axi_wready_in  (m_axi_ddr_wready),

      // --- AXI Master: Write Response Channel ---
      .axi_bresp_in   (zta_bresp),           // 1-bit, mapped from 2-bit above
      .axi_bready_out (m_axi_ddr_bready),

      // --- AXI-Lite Slave: Read Address Channel ---
      .axilite_araddr_in  (s_axi_ctrl_araddr),
      .axilite_arvalid_in (s_axi_ctrl_arvalid),
      .axilite_arready_out(s_axi_ctrl_arready),

      // --- AXI-Lite Slave: Read Data Channel ---
      .axilite_rdata_out  (s_axi_ctrl_rdata),
      .axilite_rresp_out  (s_axi_ctrl_rresp),
      .axilite_rvalid_out (s_axi_ctrl_rvalid),
      .axilite_rlast_out  (zta_ctrl_rlast),      // AXI-Lite has no rlast
      .axilite_rready_in  (s_axi_ctrl_rready),

      // --- AXI-Lite Slave: Write Address Channel ---
      .axilite_awaddr_in  (s_axi_ctrl_awaddr),
      .axilite_awvalid_in (s_axi_ctrl_awvalid),
      .axilite_awready_out(s_axi_ctrl_awready),

      // --- AXI-Lite Slave: Write Data Channel ---
      .axilite_wdata_in   (s_axi_ctrl_wdata),
      .axilite_wvalid_in  (s_axi_ctrl_wvalid),
      .axilite_wready_out (s_axi_ctrl_wready),

      // --- AXI-Lite Slave: Write Response Channel ---
      .axilite_bresp_out  (s_axi_ctrl_bresp),
      .axilite_bvalid_out (s_axi_ctrl_bvalid),
      .axilite_bready_in  (s_axi_ctrl_bready),

      // --- AXI Slave: SRAM Read Access ---
      .axislave_araddr_in  (s_axi_sram_araddr),
      .axislave_arburst_in (s_axi_sram_arburst),
      .axislave_arlen_in   (s_axi_sram_arlen),
      .axislave_arready_out(s_axi_sram_arready),
      .axislave_arsize_in  (s_axi_sram_arsize),
      .axislave_arvalid_in (s_axi_sram_arvalid),
      .axislave_rdata_out  (s_axi_sram_rdata),
      .axislave_rlast_out  (s_axi_sram_rlast),
      .axislave_rready_in  (s_axi_sram_rready),
      .axislave_rresp_out  (s_axi_sram_rresp),
      .axislave_rvalid_out (s_axi_sram_rvalid)
   );

endmodule
