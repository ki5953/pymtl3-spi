'''
==========================================================================
SPIPushPull2ValRdyAdapter_test.py
==========================================================================
Unit test for SPIPushPull2ValRdyAdapter.
'''

from pymtl3 import *
from pymtl3.stdlib.test_utils import config_model_with_cmdline_opts

from ..components.SPIPushPull2ValRdyAdapter import SPIPushPull2ValRdyAdapter

def test_basic( cmdline_opts ):

  dut = SPIPushPull2ValRdyAdapter(4, 1)
  dut = config_model_with_cmdline_opts( dut, cmdline_opts, duts=[] )
  dut.apply( DefaultPassGroup( linetrace=True ) )

  dut.push_en @= 0
  dut.pull_en @= 0
  dut.pull_msg @= 0
  dut.recv_val @= 0
  dut.recv_msg @= 0
  dut.send_rdy @= 0
  dut.sim_reset()

  # Test vectors
  #      push_en, push_msg, pull_en, pull_msg, recv_val, recv_rdy, recv_msg, send_val, send_rdy, send_msg
  t( dut,  0,      0x4,       0,     0x0,         0,        1,      0x0,       0,         0,      '?') #init
  t( dut,  0,      0x4,       0,     0xF,         0,        1,      0x3,       0,         0,      '?') #add msg no write
  t( dut,  0,      0x0,       1,     0x7,         0,        1,      0x0,       0,         0,      '?') #MOSI msg
  t( dut,  0,      0x0,       0,     0x0,         0,        1,      0x0,       1,         0,      0x3) #send msg
  t( dut,  0,      0x0,       0,     0x0,         0,        1,      0x0,       1,         1,      0x3) #accept send msg
  
  t( dut,  0,      0x4,       0,     0x0,         0,        1,      0x0,       0,         1,      '?') #empty
  t( dut,  0,      0x4,       0,     0x0,         1,        1,      0x3,       0,         1,      '?') #recv msg
  t( dut,  0,      0x7,       0,     0x0,         0,        0,      0x0,       0,         1,      '?') #MISO msg not accepted
  t( dut,  1,      0xF,       1,     0x8,         0,        0,      0x0,       0,         1,      '?') #accept MISO msg
  
  t( dut,  0,      0x7,       0,     0x0,         0,        1,      0x0,       0,         1,      '?') #empty
  t( dut,  0,      0x3,       1,     0x6,         1,        1,      0x1,       0,         1,      '?') #write both queues
  t( dut,  1,      0x9,       1,     0x8,         0,        0,      0x0,       1,         1,      0x2) #read both queues
  
  t( dut,  1,      0x1,       1,     0x5,         1,        1,      0x2,       0,         0,      '?') #multiple writes both queues
  t( dut,  0,      0x2,       1,     0x2,         1,        0,      0x1,       1,         0,      0x1) #invalid write 
  t( dut,  1,      0xA,       1,     0x8,         0,        0,      0x0,       1,         1,      0x1) #read both queues - 0xA->0xE w/queue update

  #realistic operation
  t( dut,  1,      0x6,       1,     0x2,         0,        1,      0x0,       0,         0,      '?') #empty
  t( dut,  1,      0x2,       1,     0xD,         1,        1,      0x3,       0,         0,      '?') #write both
  t( dut,  1,      0x3,       1,     0x0,         0,        0,      0x0,       1,         1,      0x1) #read mosi
  t( dut,  1,      0xB,       1,     0xF,         0,        0,      0x0,       0,         0,      '?') #read miso write mosi


def test_queue_len2( cmdline_opts ):

  dut = SPIPushPull2ValRdyAdapter(4, 2)
  dut = config_model_with_cmdline_opts( dut, cmdline_opts, duts=[] )
  dut.apply( DefaultPassGroup( linetrace=True ) )

  dut.push_en @= 0
  dut.pull_en @= 0
  dut.pull_msg @= 0
  dut.recv_val @= 0
  dut.recv_msg @= 0
  dut.send_rdy @= 0
  dut.sim_reset()

  # Test vectors
  #      push_en, push_msg, pull_en, pull_msg, recv_val, recv_rdy, recv_msg, send_val, send_rdy, send_msg
  t( dut,  0,      0x4,       0,     0x0,         0,        1,      0x0,       0,         0,      '?') #init
  t( dut,  0,      0x4,       1,     0x7,         0,        1,      0x0,       0,         0,      '?') #MOSI msg
  t( dut,  0,      0x4,       0,     0x0,         0,        1,      0x0,       1,         1,      0x3) #accept send msg
  
  t( dut,  0,      0x4,       0,     0x0,         1,        1,      0x3,       0,         1,      '?') #recv msg
  t( dut,  1,      0xF,       1,     0x8,         0,        1,      0x0,       0,         1,      '?') #accept MISO msg
  
  t( dut,  0,      0x4,       1,     0x6,         1,        1,      0x1,       0,         1,      '?') #write both queues
  t( dut,  1,      0xD,       1,     0x8,         0,        1,      0x0,       1,         1,      0x2) #read both queues
  
  t( dut,  1,      0x7,       1,     0x5,         1,        1,      0x2,       0,         0,      '?') #write both queues
  t( dut,  0,      0x2,       1,     0x6,         1,        1,      0x1,       1,         0,      '?') #write both queues
  # t( dut,  1,      0xA,       1,     0x8,         0,        0,      0x0,       1,         1,      0x1) #read both queues - change w/queue update
  # t( dut,  1,      0xA,       1,     0x8,         0,        0,      0x0,       1,         1,      0x1) #read both queues - change w/queue update

  # #realistic operation
  # t( dut,  1,      0x6,       1,     0x2,         0,        1,      0x0,       0,         0,      '?') #empty
  # t( dut,  1,      0x2,       1,     0xD,         1,        1,      0x3,       0,         0,      '?') #write both
  # t( dut,  1,      0x3,       1,     0x0,         0,        0,      0x0,       1,         1,      0x1) #read mosi
  # t( dut,  1,      0xB,       1,     0xF,         0,        0,      0x0,       0,         0,      '?') #read miso write mosi


# Helper function
def t( dut, push_en, push_msg, pull_en, pull_msg, recv_val, recv_rdy, recv_msg, send_val, send_rdy, send_msg ):

  # Write input value to input port
  dut.push_en @= push_en
  dut.pull_en @= pull_en
  dut.pull_msg @= pull_msg
  dut.recv_val @= recv_val
  dut.recv_msg @= recv_msg
  dut.send_rdy @= send_rdy

  dut.sim_eval_combinational()


  print(f"mc_deq_en {dut.mosiqueue.deq.en} mc_enq_en {dut.mosiqueue.enq.en} mc_enq_rdy {dut.mosiqueue.enq.rdy} mc_enq_msg {dut.mosiqueue.enq.msg} cm_enq_en {dut.misoqueue.enq.en} cm_deq_en {dut.misoqueue.deq.en} cm_deq_rdy {dut.misoqueue.deq.rdy} mc_cnt {dut.mosiqueue.count} cm_cnt {dut.misoqueue.count} val_wrt {dut.pull_msg[dut.nbits-2]} pull_en {dut.pull_en} pull_msg {dut.pull_msg} push_en {dut.push_en} val_res {dut.push_msg[dut.nbits-1]} push_msg {dut.push_msg} cm_deq_msg {dut.misoqueue.deq.ret} flw_bit {dut.flow_bit} opn_ents {dut.open_entries}")

  if push_msg != '?':
    assert dut.push_msg == push_msg

  if recv_rdy != '?':
    assert dut.recv_rdy == recv_rdy

  if send_val != '?':
    assert dut.send_val == send_val

  if send_msg != '?':
    assert dut.send_msg == send_msg

  # Tick simulator one cycle
  dut.sim_tick()