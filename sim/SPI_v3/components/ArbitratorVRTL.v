// ==========================================================================
// Arbitrator.py
// ==========================================================================
// This module is used to pick which component gets to output to the val/rdy SPI wrapper if multiple components can send a valid message.
// The arbitrator puts an address header on the outgoing packet so that downstream components can tell which component sent the response
// The nbits parameter is the length of the message.
// The num_inputs parameter is the number of input components that the Arbitrator is selecting from. MUST be >= 2

// Author : Dilan Lakhani
//   Date : Dec 19, 2021


module ArbitratorVRTL
#(
  parameter nbits = 32,
  parameter num_inputs = 6,
  parameter addr_nbits = $clog2(num_inputs)
)
(
  input clk,
  input reset,

  // Receive Interface - need req signals for each component connected to arbitrator
  input                          req_val [num_inputs-1:0],
  output                         req_rdy [num_inputs-1:0],
  input  [nbits-1:0]             req_msg [num_inputs-1:0],

  // Send Interface
  output                         resp_val,
  input                          resp_rdy,
  output [addr_nbits+nbits-1:0]  resp_msg
);

  logic [addr_nbits-1:0] grants_index; // which input is granted access to send to SPI
  logic [addr_nbits-1:0] old_grants_index;
  logic [addr_nbits-1:0] encoder_out;

  assign resp_val = req_val[grants_index] & req_rdy[grants_index];
  assign resp_msg = {grants_index, req_msg[grants_index]}; // append component address to the beginning of the message
    
  always_comb begin
    // change grants_index if the last cycle's grant index is 0 (that component has finished sending its message)
    if (!req_val[old_grants_index]) begin
      grants_index = encoder_out;
    end
    else begin
      grants_index = grants_index;
    end
  end

  always_comb begin
    // Only tell one input that the arbitrator is ready for it
    req_rdy = 0;
    req_rdy[grants_index] = resp_rdy;
  end
    
  always_comb begin
    // priority encoder that gives highest priority to the LSB and lowest to MSB
    encoder_out = 0;
    for(integer i=0; i<num_inputs; i++) begin
      if (req_val[num_inputs-1-i]) begin
        encoder_out = num_inputs-1-i;
      end
    end
  end

  // One issue arises with having multiple Disassemblers. Since the SPI width is normally less than the size of a response,
  // a PacketDisassembler component needs multiple cycles to fully send a message to the arbitrator. Thus, we do not want to 
  // change which Disassembler is allowed to send to the Arbitrator in the middle of a message.
  // Fix this by holding a trailing value of the grants_index.
  // We need to be able to check the req_val of the old grants_index to make sure that it is not 1, then we can allow a different
  // Disassembler to send a message
  always_ff @(posedge clk) begin
    if (reset) begin
      old_grants_index <= 0;
    end
    else begin
      old_grants_index <= grants_index;
    end
  end

endmodule


