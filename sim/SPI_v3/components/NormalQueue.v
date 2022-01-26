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

module NormalQueueCtrlRTL
(
  input  logic       clk ,
  output logic [2:0] count ,
  output logic [2:0] raddr ,
  output logic [0:0] recv_rdy ,
  input  logic [0:0] recv_val ,
  input  logic [0:0] reset ,
  input  logic [0:0] send_rdy ,
  output logic [0:0] send_val ,
  output logic [2:0] waddr ,
  output logic [0:0] wen 
);
  localparam logic [2:0] __const__num_entries_at__lambda__s_cm_q_ctrl_recv_rdy  = 3'd5;
  localparam logic [2:0] __const__num_entries_at_up_reg  = 3'd5;
  logic [2:0] head;
  logic [0:0] recv_xfer;
  logic [0:0] send_xfer;
  logic [2:0] tail;

  // PyMTL Lambda Block Source
  // At /work/global/brg/install/venv-pkgs/x86_64-centos7/python3.7.4/lib/python3.7/site-packages/pymtl3/stdlib/stream/queues.py:121
  // s.recv_rdy  //= lambda: s.count < num_entries
  
  always_comb begin : _lambda__s_cm_q_ctrl_recv_rdy
    recv_rdy = count < 3'( __const__num_entries_at__lambda__s_cm_q_ctrl_recv_rdy );
  end

  // PyMTL Lambda Block Source
  // At /work/global/brg/install/venv-pkgs/x86_64-centos7/python3.7.4/lib/python3.7/site-packages/pymtl3/stdlib/stream/queues.py:124
  // s.recv_xfer //= lambda: s.recv_val & s.recv_rdy
  
  always_comb begin : _lambda__s_cm_q_ctrl_recv_xfer
    recv_xfer = recv_val & recv_rdy;
  end

  // PyMTL Lambda Block Source
  // At /work/global/brg/install/venv-pkgs/x86_64-centos7/python3.7.4/lib/python3.7/site-packages/pymtl3/stdlib/stream/queues.py:122
  // s.send_val  //= lambda: s.count > 0
  
  always_comb begin : _lambda__s_cm_q_ctrl_send_val
    send_val = count > 3'd0;
  end

  // PyMTL Lambda Block Source
  // At /work/global/brg/install/venv-pkgs/x86_64-centos7/python3.7.4/lib/python3.7/site-packages/pymtl3/stdlib/stream/queues.py:125
  // s.send_xfer //= lambda: s.send_val & s.send_rdy
  
  always_comb begin : _lambda__s_cm_q_ctrl_send_xfer
    send_xfer = send_val & send_rdy;
  end

  // PyMTL Update Block Source
  // At /work/global/brg/install/venv-pkgs/x86_64-centos7/python3.7.4/lib/python3.7/site-packages/pymtl3/stdlib/stream/queues.py:127
  // @update_ff
  // def up_reg():
  // 
  //   if s.reset:
  //     s.head  <<= 0
  //     s.tail  <<= 0
  //     s.count <<= 0
  // 
  //   else:
  //     if s.recv_xfer:
  //       s.tail <<= s.tail + 1 if ( s.tail < num_entries - 1 ) else 0
  // 
  //     if s.send_xfer:
  //       s.head <<= s.head + 1 if ( s.head < num_entries -1 ) else 0
  // 
  //     if s.recv_xfer & ~s.send_xfer:
  //       s.count <<= s.count + 1
  //     elif ~s.recv_xfer & s.send_xfer:
  //       s.count <<= s.count - 1
  
  always_ff @(posedge clk) begin : up_reg
    if ( reset ) begin
      head <= 3'd0;
      tail <= 3'd0;
      count <= 3'd0;
    end
    else begin
      if ( recv_xfer ) begin
        tail <= ( tail < ( 3'( __const__num_entries_at_up_reg ) - 3'd1 ) ) ? tail + 3'd1 : 3'd0;
      end
      if ( send_xfer ) begin
        head <= ( head < ( 3'( __const__num_entries_at_up_reg ) - 3'd1 ) ) ? head + 3'd1 : 3'd0;
      end
      if ( recv_xfer & ( ~send_xfer ) ) begin
        count <= count + 3'd1;
      end
      else if ( ( ~recv_xfer ) & send_xfer ) begin
        count <= count - 3'd1;
      end
    end
  end

  assign wen = recv_xfer;
  assign waddr = tail;
  assign raddr = head;

endmodule


// PyMTL Component RegisterFile Definition
// Full name: RegisterFile__Type_Bits2__nregs_5__rd_ports_1__wr_ports_1__const_zero_False
// At /work/global/brg/install/venv-pkgs/x86_64-centos7/python3.7.4/lib/python3.7/site-packages/pymtl3/stdlib/basic_rtl/register_files.py

module RegisterFile__f139692140de1d4f
(
  input  logic [0:0] clk ,
  input  logic [2:0] raddr [0:0],
  output logic [1:0] rdata [0:0],
  input  logic [0:0] reset ,
  input  logic [2:0] waddr [0:0],
  input  logic [1:0] wdata [0:0],
  input  logic [0:0] wen [0:0]
);
  localparam logic [0:0] __const__rd_ports_at_up_rf_read  = 1'd1;
  localparam logic [0:0] __const__wr_ports_at_up_rf_write  = 1'd1;
  logic [1:0] regs [0:4];

  // PyMTL Update Block Source
  // At /work/global/brg/install/venv-pkgs/x86_64-centos7/python3.7.4/lib/python3.7/site-packages/pymtl3/stdlib/basic_rtl/register_files.py:20
  // @update
  // def up_rf_read():
  //   for i in range( rd_ports ):
  //     s.rdata[i] @= s.regs[ s.raddr[i] ]
  
  always_comb begin : up_rf_read
    for ( int unsigned i = 1'd0; i < 1'( __const__rd_ports_at_up_rf_read ); i += 1'd1 )
      rdata[1'(i)] = regs[raddr[1'(i)]];
  end

  // PyMTL Update Block Source
  // At /work/global/brg/install/venv-pkgs/x86_64-centos7/python3.7.4/lib/python3.7/site-packages/pymtl3/stdlib/basic_rtl/register_files.py:32
  // @update_ff
  // def up_rf_write():
  //   for i in range( wr_ports ):
  //     if s.wen[i]:
  //       s.regs[ s.waddr[i] ] <<= s.wdata[i]
  
  always_ff @(posedge clk) begin : up_rf_write
    for ( int unsigned i = 1'd0; i < 1'( __const__wr_ports_at_up_rf_write ); i += 1'd1 )
      if ( wen[1'(i)] ) begin
        regs[waddr[1'(i)]] <= wdata[1'(i)];
      end
  end

endmodule


// PyMTL Component NormalQueueDpathRTL Definition
// At /work/global/brg/install/venv-pkgs/x86_64-centos7/python3.7.4/lib/python3.7/site-packages/pymtl3/stdlib/stream/queues.py

module NormalQueueDpathRTL__EntryType_Bits2__num_entries_5
(
  input  logic [0:0] clk ,
  input  logic [2:0] raddr ,
  input  logic [1:0] recv_msg ,
  input  logic [0:0] reset ,
  output logic [1:0] send_msg ,
  input  logic [2:0] waddr ,
  input  logic [0:0] wen 
);
  //-------------------------------------------------------------
  // Component rf
  //-------------------------------------------------------------

  logic [0:0] rf__clk;
  logic [2:0] rf__raddr [0:0];
  logic [1:0] rf__rdata [0:0];
  logic [0:0] rf__reset;
  logic [2:0] rf__waddr [0:0];
  logic [1:0] rf__wdata [0:0];
  logic [0:0] rf__wen [0:0];

  RegisterFile__f139692140de1d4f rf
  (
    .clk( rf__clk ),
    .raddr( rf__raddr ),
    .rdata( rf__rdata ),
    .reset( rf__reset ),
    .waddr( rf__waddr ),
    .wdata( rf__wdata ),
    .wen( rf__wen )
  );

  //-------------------------------------------------------------
  // End of component rf
  //-------------------------------------------------------------

  assign rf__clk = clk;
  assign rf__reset = reset;
  assign rf__raddr[0] = raddr;
  assign send_msg = rf__rdata[0];
  assign rf__wen[0] = wen;
  assign rf__waddr[0] = waddr;
  assign rf__wdata[0] = recv_msg;

endmodule


// PyMTL Component NormalQueueRTL Definition
// At /work/global/brg/install/venv-pkgs/x86_64-centos7/python3.7.4/lib/python3.7/site-packages/pymtl3/stdlib/stream/queues.py

module NormalQueueRTL__EntryType_Bits2__num_entries_5
(
  input  logic [0:0] clk ,
  output logic [2:0] count ,
  input  logic [0:0] reset ,
  input logic [1:0] recv__msg  ,
  output logic [0:0] recv__rdy  ,
  input logic [0:0] recv__val  ,
  output logic [1:0] send__msg  ,
  input logic [0:0] send__rdy  ,
  output logic [0:0] send__val  
);
  //-------------------------------------------------------------
  // Component ctrl
  //-------------------------------------------------------------

  logic [0:0] ctrl__clk;
  logic [2:0] ctrl__count;
  logic [2:0] ctrl__raddr;
  logic [0:0] ctrl__recv_rdy;
  logic [0:0] ctrl__recv_val;
  logic [0:0] ctrl__reset;
  logic [0:0] ctrl__send_rdy;
  logic [0:0] ctrl__send_val;
  logic [2:0] ctrl__waddr;
  logic [0:0] ctrl__wen;

  NormalQueueCtrlRTL__num_entries_5 ctrl
  (
    .clk( ctrl__clk ),
    .count( ctrl__count ),
    .raddr( ctrl__raddr ),
    .recv_rdy( ctrl__recv_rdy ),
    .recv_val( ctrl__recv_val ),
    .reset( ctrl__reset ),
    .send_rdy( ctrl__send_rdy ),
    .send_val( ctrl__send_val ),
    .waddr( ctrl__waddr ),
    .wen( ctrl__wen )
  );

  //-------------------------------------------------------------
  // End of component ctrl
  //-------------------------------------------------------------

  //-------------------------------------------------------------
  // Component dpath
  //-------------------------------------------------------------

  logic [0:0] dpath__clk;
  logic [2:0] dpath__raddr;
  logic [1:0] dpath__recv_msg;
  logic [0:0] dpath__reset;
  logic [1:0] dpath__send_msg;
  logic [2:0] dpath__waddr;
  logic [0:0] dpath__wen;

  NormalQueueDpathRTL__EntryType_Bits2__num_entries_5 dpath
  (
    .clk( dpath__clk ),
    .raddr( dpath__raddr ),
    .recv_msg( dpath__recv_msg ),
    .reset( dpath__reset ),
    .send_msg( dpath__send_msg ),
    .waddr( dpath__waddr ),
    .wen( dpath__wen )
  );

  //-------------------------------------------------------------
  // End of component dpath
  //-------------------------------------------------------------

  assign ctrl__clk = clk;
  assign ctrl__reset = reset;
  assign dpath__clk = clk;
  assign dpath__reset = reset;
  assign dpath__wen = ctrl__wen;
  assign dpath__waddr = ctrl__waddr;
  assign dpath__raddr = ctrl__raddr;
  assign ctrl__recv_val = recv__val;
  assign recv__rdy = ctrl__recv_rdy;
  assign dpath__recv_msg = recv__msg;
  assign send__val = ctrl__send_val;
  assign ctrl__send_rdy = send__rdy;
  assign send__msg = dpath__send_msg;
  assign count = ctrl__count;

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