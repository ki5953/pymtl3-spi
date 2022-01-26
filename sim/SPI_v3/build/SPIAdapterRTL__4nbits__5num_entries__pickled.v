//-------------------------------------------------------------------------
// SPIAdapterRTL__4nbits__5num_entries.v
//-------------------------------------------------------------------------
// This file is generated by PyMTL SystemVerilog translation pass.

// PyMTL VerilogPlaceholder SPIAdapterVRTL Definition
// Full name: SPIAdapterVRTL__nbits_4__num_entries_5
// At /work/global/ki88/spi_minion_fork/sim/SPI_v3/components/SPIAdapterRTL.py

//***********************************************************
// Pickled source file of placeholder SPIAdapterVRTL__nbits_4__num_entries_5
//***********************************************************

//-----------------------------------------------------------
// Dependency of placeholder SPIAdapterVRTL
//-----------------------------------------------------------

`ifndef SPIADAPTERVRTL
`define SPIADAPTERVRTL

// The source code below are included because they are specified
// as the v_libs Verilog placeholder option of component SPIAdapterVRTL__nbits_4__num_entries_5.

// If you get a duplicated def error from files included below, please
// make sure they are included either through the v_libs option or the
// explicit `include statement in the Verilog source code -- if they
// appear in both then they will be included twice!


// End of all v_libs files for component SPIAdapterVRTL__nbits_4__num_entries_5

`line 1 "SPI_v3/components/SPIAdapterVRTL.v" 0
//-------------------------------------------------------------------------
// SPIAdapterVRTL.v
//-------------------------------------------------------------------------
`line 1 "SPI_v3/components/NormalQueue.v" 0
//==========================================================================
//NormalQueue.v
//==========================================================================

module NormalQueue1Entry
#(
    parameter nbits = 8
)
(
  input  logic             clk,
  output logic             count,
  input  logic             reset,
  input  logic [nbits-1:0] recv_msg,
  output logic             recv_rdy,
  input  logic             recv_val,
  output logic [nbits-1:0] send_msg,
  input  logic             send_rdy,
  output logic             send_val  
);

  logic [nbits-1:0] entry;
  logic             full;
  
  always_comb begin
    recv_rdy = ~full;
  end
  
  always_ff @(posedge clk) begin
    if ( reset ) begin
      full <= 1'b0;
    end
    else
      full <= ( recv_val & ( ~full ) ) | ( full & ( ~send_rdy ) );
    if ( recv_val & ( ~full ) ) begin
      entry <= recv_msg;
    end
  end

  assign count = full;
  assign send_msg = entry;
  assign send_val = full;

endmodule


module NormalQueueRTL
#(
    parameter nbits = 8,
    parameter num_entries = 1
)
(
  input  logic                   clk,
  output logic [$clog2(nbits):0] count,
  input  logic                   reset,
  input  logic [nbits-1:0]       recv_msg,
  output logic                   recv_rdy,
  input  logic                   recv_val,
  output logic [nbits-1:0]       send_msg,
  input  logic                   send_rdy,
  output logic                   send_val  
);
  if (num_entries == 1) begin
    logic             q_clk;
    logic             q_count;
    logic             q_reset;
    logic [nbits-1:0] q_recv_msg;
    logic             q_recv_rdy;
    logic             q_recv_val;
    logic [nbits-1:0] q_send_msg;
    logic             q_send_rdy;
    logic             q_send_val;
    
    NormalQueue1Entry q
    (
      .clk( q_clk ),
      .count( q_count ),
      .reset( q_reset ),
      .recv_msg( q_recv_msg ),
      .recv_rdy( q_recv_rdy ),
      .recv_val( q_recv_val ),
      .send_msg( q_send_msg ),
      .send_rdy( q_send_rdy ),
      .send_val( q_send_val )
    );

    assign q_clk = clk;
    assign q_reset = reset;
    assign q_recv_msg = recv_msg;
    assign recv_rdy = q_recv_rdy;
    assign q_recv_val = recv_val;
    assign send_msg = q_send_msg;
    assign q_send_rdy = send_rdy;
    assign send_val = q_send_val;
    assign count = q_count;
  end
  else begin

    localparam addr_bits = $clog2(nbits);

    logic [addr_bits-1:0] head;
    logic                 recv_xfer;
    logic                 send_xfer;
    logic [addr_bits-1:0] tail;
    
    always_comb begin
      recv_rdy = count < num_entries;
      recv_xfer = recv_val & recv_rdy;
      send_val = count > { addr_bits{1'b0} };
      send_xfer = send_val & send_rdy;
    end
      
    always_ff @(posedge clk) begin
      if ( reset ) begin
        head <= { addr_bits{1'b0} };
        tail <= { addr_bits{1'b0} };
        count <= { addr_bits{1'b0} };
      end
      else begin
        if ( recv_xfer ) begin
          tail <= ( tail < (num_entries-1)) ? tail + 1'd1 : 1'd0;
        end
        if ( send_xfer ) begin
          head <= ( head < (num_entries-1)) ? head + 1'd1 : 1'd0;
        end
        if ( recv_xfer & ( ~send_xfer ) ) begin
          count <= count + 1'd1;
        end
        else if ( ( ~recv_xfer ) & send_xfer ) begin
          count <= count - 1'd1;
        end
      end
    end
    
    assign wen = recv_xfer;
    assign waddr = tail;
    assign raddr = head;
  end

endmodule
`line 5 "SPI_v3/components/SPIAdapterVRTL.v" 0

module SPI_v3_components_SPIAdapterVRTL
#(
  parameter nbits = 8,
  parameter num_entries = 1
)
(
  input  logic                    clk,
  input  logic                    reset,
  input  logic                    pull_en,
  output logic                    pull_msg_val,
  output logic                    pull_msg_spc,
  output logic [nbits-1:0]        pull_msg_data,
  input  logic                    push_en,
  input  logic                    push_msg_val_wrt,
  input  logic                    push_msg_val_rd,
  input  logic [nbits-1:0]        push_msg_data,
  input  logic [nbits-3:0]        recv_msg,
  output logic                    recv_rdy,
  input  logic                    recv_val,
  output logic [nbits-3:0]        send_msg,
  input  logic                    send_rdy,
  output logic                    send_val  
);

  logic cm_send_rdy;
  logic mc_recv_val;
  logic open_entries;
  //-------------------------------------------------------------
  // Component cm_q
  //-------------------------------------------------------------

  logic             cm_q_clk;
  logic             cm_q_count;
  logic             cm_q_reset;
  logic [nbits-3:0] cm_q_recv_msg;
  logic             cm_q_recv_rdy;
  logic             cm_q_recv_val;
  logic [nbits-3:0] cm_q_send_msg;
  logic             cm_q_send_rdy;
  logic             cm_q_send_val;

  NormalQueueRTL #(nbits, num_entries) cm_q
  (
    .clk( cm_q_clk ),
    .count( cm_q_count ),
    .reset( cm_q_reset ),
    .recv_msg( cm_q_recv_msg ),
    .recv_rdy( cm_q_recv_rdy ),
    .recv_val( cm_q_recv_val ),
    .send_msg( cm_q_send_msg ),
    .send_rdy( cm_q_send_rdy ),
    .send_val( cm_q_send_val )
  );

  //-------------------------------------------------------------
  // End of component cm_q
  //-------------------------------------------------------------

  //-------------------------------------------------------------
  // Component mc_q
  //-------------------------------------------------------------

  logic             mc_q_clk;
  logic             mc_q_count;
  logic             mc_q_reset;
  logic [nbits-1:0] mc_q_recv_msg;
  logic             mc_q_recv_rdy;
  logic             mc_q_recv_val;
  logic [nbits-1:0] mc_q_send_msg;
  logic             mc_q_send_rdy;
  logic             mc_q_send_val;

  NormalQueueRTL #(nbits, num_entries) mc_q
  (
    .clk( mc_q_clk ),
    .count( mc_q_count ),
    .reset( mc_q_reset ),
    .recv_msg( mc_q_recv_msg ),
    .recv_rdy( mc_q_recv_rdy ),
    .recv_val( mc_q_recv_val ),
    .send_msg( mc_q_send_msg ),
    .send_rdy( mc_q_send_rdy ),
    .send_val( mc_q_send_val )
  );

  //-------------------------------------------------------------
  // End of component mc_q
  //-------------------------------------------------------------
  
  always_comb begin : comb_block
    open_entries = mc_q_count < ( num_entries-1 );
    mc_recv_val = push_msg_val_wrt & push_en;
    pull_msg_spc = mc_q_recv_rdy & ( ( ~mc_q_recv_val ) | open_entries );
    cm_send_rdy = push_msg_val_rd & pull_en;
    pull_msg_val = cm_send_rdy & cm_q_send_val;
    pull_msg_data = cm_q_send_msg & { (nbits-2){pull_msg_val} };
  end

  assign mc_q_clk = clk;
  assign mc_q_reset = reset;
  assign send_val = mc_q_send_val;
  assign send_msg = mc_q_send_msg;
  assign mc_q_send_rdy = send_rdy;
  assign mc_q_recv_val = mc_recv_val;
  assign mc_q_recv_msg = push_msg_data;
  assign cm_q_clk = clk;
  assign cm_q_reset = reset;
  assign cm_q_recv_val = recv_val;
  assign recv_rdy = cm_q_recv_rdy;
  assign cm_q_recv_msg = recv_msg;
  assign cm_q_send_rdy = cm_send_rdy;

endmodule

`endif /* SPIADAPTERVRTL */
//-----------------------------------------------------------
// Wrapper of placeholder SPIAdapterVRTL__nbits_4__num_entries_5
//-----------------------------------------------------------

`ifndef SPIADAPTERVRTL__NBITS_4__NUM_ENTRIES_5
`define SPIADAPTERVRTL__NBITS_4__NUM_ENTRIES_5

module SPIAdapterRTL__4nbits__5num_entries
(
  input logic [1-1:0] clk ,
  input logic [1-1:0] pull_en ,
  output logic [2-1:0] pull_msg_data ,
  output logic [1-1:0] pull_msg_spc ,
  output logic [1-1:0] pull_msg_val ,
  input logic [1-1:0] push_en ,
  input logic [2-1:0] push_msg_data ,
  input logic [1-1:0] push_msg_val_rd ,
  input logic [1-1:0] push_msg_val_wrt ,
  input logic [1-1:0] reset ,
  input logic [2-1:0] recv_msg ,
  output logic [1-1:0] recv_rdy ,
  input logic [1-1:0] recv_val ,
  output logic [2-1:0] send_msg ,
  input logic [1-1:0] send_rdy ,
  output logic [1-1:0] send_val 
);
  SPI_v3_components_SPIAdapterVRTL
  #(
    .nbits( 4 ),
    .num_entries( 5 )
  ) v
  (
    .clk( clk ),
    .pull_en( pull_en ),
    .pull_msg_data( pull_msg_data ),
    .pull_msg_spc( pull_msg_spc ),
    .pull_msg_val( pull_msg_val ),
    .push_en( push_en ),
    .push_msg_data( push_msg_data ),
    .push_msg_val_rd( push_msg_val_rd ),
    .push_msg_val_wrt( push_msg_val_wrt ),
    .reset( reset ),
    .recv_msg( recv_msg ),
    .recv_rdy( recv_rdy ),
    .recv_val( recv_val ),
    .send_msg( send_msg ),
    .send_rdy( send_rdy ),
    .send_val( send_val )
  );
endmodule

`endif /* SPIADAPTERVRTL__NBITS_4__NUM_ENTRIES_5 */

