//========================================================================
// VSPIAdapterPRTL__nbits_4__num_entries_2_v.cpp
//========================================================================
// This file provides a template for the C wrapper used in the import
// pass. The wrapper exposes a C interface to CFFI so that a
// Verilator-generated C++ model can be driven from Python.
// This templated is based on PyMTL v2.

#include "obj_dir_SPIAdapterPRTL__nbits_4__num_entries_2/VSPIAdapterPRTL__nbits_4__num_entries_2.h"
#include "stdio.h"
#include "stdint.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

// set to true if the model has clk signal
#define HAS_CLK 1

// set to true when VCD tracing is enabled in Verilator
#define DUMP_VCD 0

// set to true to enable on-demand VCD dumping
#define ON_DEMAND_DUMP_VCD 0

// top level port to be used in on-demand VCD dumping; only dump vars when
// that port has a non-zero value.
#define ON_DEMAND_VCD_ENABLE 0

// set to true when Verilog module has line tracing
#define VLINETRACE 0

#if VLINETRACE
#include "obj_dir_SPIAdapterPRTL__nbits_4__num_entries_2/VSPIAdapterPRTL__nbits_4__num_entries_2__Syms.h"
#include "svdpi.h"
#endif

//------------------------------------------------------------------------
// CFFI Interface
//------------------------------------------------------------------------
// simulation methods and model interface ports exposed to CFFI

extern "C" {
  typedef struct {

    // Exposed port interface
    unsigned char * clk;
    unsigned char * reset;
    unsigned char * pull___05Fen;
    unsigned char * pull___05Fmsg;
    unsigned char * push___05Fen;
    unsigned char * push___05Fmsg;
    unsigned char * recv___05Fmsg;
    unsigned char * recv___05Frdy;
    unsigned char * recv___05Fval;
    unsigned char * send___05Fmsg;
    unsigned char * send___05Frdy;
    unsigned char * send___05Fval;

    // Verilator model
    void * model;

    // VCD state
    int _vcd_en;

    // VCD tracing helpers
    #if DUMP_VCD
    void *        tfp;
    unsigned int  trace_time;
    #endif

  } VSPIAdapterPRTL__nbits_4__num_entries_2_t;

  // Exposed methods
  VSPIAdapterPRTL__nbits_4__num_entries_2_t * create_model( const char * );
  void destroy_model( VSPIAdapterPRTL__nbits_4__num_entries_2_t *);
  void comb_eval( VSPIAdapterPRTL__nbits_4__num_entries_2_t * );
  void seq_eval( VSPIAdapterPRTL__nbits_4__num_entries_2_t * );
  void assert_en( bool en );

  #if VLINETRACE
  void trace( VSPIAdapterPRTL__nbits_4__num_entries_2_t *, char * );
  #endif

}

//------------------------------------------------------------------------
// sc_time_stamp
//------------------------------------------------------------------------
// Must be defined so the simulator knows the current time. Called by
// $time in Verilog. See:
// http://www.veripool.org/projects/verilator/wiki/Faq

vluint64_t g_main_time = 0;

double sc_time_stamp()
{

  return g_main_time;

}

//------------------------------------------------------------------------
// create_model()
//------------------------------------------------------------------------
// Construct a new verilator simulation, initialize interface signals
// exposed via CFFI, and setup VCD tracing if enabled.

VSPIAdapterPRTL__nbits_4__num_entries_2_t * create_model( const char *vcd_filename ) {

  VSPIAdapterPRTL__nbits_4__num_entries_2_t * m;
  VSPIAdapterPRTL__nbits_4__num_entries_2   * model;

  Verilated::randReset( 0 );
  Verilated::randSeed( 0 );

  m     = (VSPIAdapterPRTL__nbits_4__num_entries_2_t *) malloc( sizeof(VSPIAdapterPRTL__nbits_4__num_entries_2_t) );
  model = new VSPIAdapterPRTL__nbits_4__num_entries_2();

  m->model = (void *) model;

  // Enable tracing. We have added a feature where if the vcd_filename is
  // "" then we don't do any VCD dumping even if DUMP_VCD is true.

  m->_vcd_en = 0;
  #if DUMP_VCD
  if ( strlen( vcd_filename ) != 0 ) {
    m->_vcd_en = 1;
    Verilated::traceEverOn( true );
    VerilatedVcdC * tfp = new VerilatedVcdC();

    model->trace( tfp, 99 );
    tfp->spTrace()->set_time_resolution( "10ps" );
    tfp->open( vcd_filename );

    m->tfp        = (void *) tfp;
    m->trace_time = 0;
  }
  #endif

  // initialize exposed model interface pointers
  m->clk = &model->clk;
  m->reset = &model->reset;
  m->pull___05Fen = &model->pull___05Fen;
  m->pull___05Fmsg = &model->pull___05Fmsg;
  m->push___05Fen = &model->push___05Fen;
  m->push___05Fmsg = &model->push___05Fmsg;
  m->recv___05Fmsg = &model->recv___05Fmsg;
  m->recv___05Frdy = &model->recv___05Frdy;
  m->recv___05Fval = &model->recv___05Fval;
  m->send___05Fmsg = &model->send___05Fmsg;
  m->send___05Frdy = &model->send___05Frdy;
  m->send___05Fval = &model->send___05Fval;

  return m;

}

//------------------------------------------------------------------------
// destroy_model()
//------------------------------------------------------------------------
// Finalize the Verilator simulation, close files, call destructors.

void destroy_model( VSPIAdapterPRTL__nbits_4__num_entries_2_t * m ) {

  #if VM_COVERAGE
    VerilatedCov::write( "coverage.dat" );
  #endif

  VSPIAdapterPRTL__nbits_4__num_entries_2 * model = (VSPIAdapterPRTL__nbits_4__num_entries_2 *) m->model;

  // finalize verilator simulation
  model->final();

  #if DUMP_VCD
  if ( m->_vcd_en ) {
    // printf("DESTROYING %d\n", m->trace_time);
    VerilatedVcdC * tfp = (VerilatedVcdC *) m->tfp;
    tfp->close();
  }
  #endif

  delete model;

}

//------------------------------------------------------------------------
// comb_eval()
//------------------------------------------------------------------------
// Simulate one time-step in the Verilated model.

void comb_eval( VSPIAdapterPRTL__nbits_4__num_entries_2_t * m ) {

  VSPIAdapterPRTL__nbits_4__num_entries_2 * model = (VSPIAdapterPRTL__nbits_4__num_entries_2 *) m->model;

  // evaluate one time step
  model->eval();

  // Shunning: calling dump multiple times leads to unsuppressable warning
  //           under verilator 4.036
  // #if DUMP_VCD
  // if ( m->_vcd_en ) {
  //   // dump current signal values
  //   VerilatedVcdC * tfp = (VerilatedVcdC *) m->tfp;
  //   tfp->dump( m->trace_time );
  //   tfp->flush();
  // }
  // #endif

}

//------------------------------------------------------------------------
// seq_eval()
//------------------------------------------------------------------------
// Simulate the positive clock edge in the Verilated model.

void seq_eval( VSPIAdapterPRTL__nbits_4__num_entries_2_t * m ) {

  VSPIAdapterPRTL__nbits_4__num_entries_2 * model = (VSPIAdapterPRTL__nbits_4__num_entries_2 *) m->model;

  // evaluate one time cycle

  #if HAS_CLK
  model->clk = 0;
  #endif

  model->eval();

  #if DUMP_VCD
  if ( m->_vcd_en && (ON_DEMAND_VCD_ENABLE || !ON_DEMAND_DUMP_VCD) ) {

    // update simulation time only on clock toggle
    m->trace_time += 50;
    g_main_time   += 50;

    // dump current signal values
    VerilatedVcdC * tfp = (VerilatedVcdC *) m->tfp;
    tfp->dump( m->trace_time );
    tfp->flush();

  }
  #endif

  #if HAS_CLK
  model->clk = 1;
  #endif

  model->eval();

  #if DUMP_VCD
  if ( m->_vcd_en && (ON_DEMAND_VCD_ENABLE || !ON_DEMAND_DUMP_VCD) ) {

    // update simulation time only on clock toggle
    m->trace_time += 50;
    g_main_time += 50;

    // dump current signal values
    VerilatedVcdC * tfp = (VerilatedVcdC *) m->tfp;
    tfp->dump( m->trace_time );
    tfp->flush();

  }
  #endif
}

//------------------------------------------------------------------------
// assert_en()
//------------------------------------------------------------------------
// Enable or disable assertions controlled by --assert

void assert_en( bool en ) {

  Verilated::assertOn(en);

}

//------------------------------------------------------------------------
// trace()
//------------------------------------------------------------------------
// Note that we assume a trace string buffer of 512 characters. This is
// assumed in a couple of places, including the Python wrapper template
// and the Verilog vc/trace.v code. So if we change it, we need to change
// it everywhere.

#if VLINETRACE
void trace( VSPIAdapterPRTL__nbits_4__num_entries_2_t * m, char* str ) {

  VSPIAdapterPRTL__nbits_4__num_entries_2 * model = (VSPIAdapterPRTL__nbits_4__num_entries_2 *) m->model;

  const int nchars = 512;
  const int nwords = nchars/4;

  uint32_t words[nwords];
  words[0] = nchars-1;

  // Setup scope for accessing the line tracing function throug DPI.
  // Note, I tried using just this:
  //
  //  svSetScope( svGetScopeFromName("TOP.v.verilog_module") );
  //
  // but it did not seem to work. We would see correct line tracing for
  // the first test case but not any of the remaining tests cases. After
  // digging around a bit, it seemed like the line_trace task was still
  // associated with the very first model as opposed to the newly
  // instantiated models. Directly setting the scope seemed to fix
  // this issue.
  //
  // Note that this issue implies that the mysterious extra .v is no
  // longer present:
  //
  //  https://www.veripool.org/issues/1050-Verilator-Extra-v-in-full-signal-pathnames
  //
  // So now we need to explicitly use the model name instead of
  // Vscope_v__verilog_module.

  // PP: also note that since we add a wrapper around the external Verilog
  // module, the scope we are trying to set is actually the _wrapped_ module
  // which is called `v`.

  svSetScope( &model->__VlSymsp->__Vscope_SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_2__v );
  model->line_trace( words );

  // Note that the way the line tracing works, the line tracing function
  // will store how the last character used in the line trace in the
  // first element of the word array. The line tracing functions store
  // the line trace starting from the most-signicant character due to the
  // way that Verilog handles strings.

  int nchar_last  = words[0];
  int nchars_used = ( nchars - 1 - nchar_last );

  // We subtract since one of the words (i.e., 4 characters) is for
  // storing the nchars_used.

  assert ( nchars_used < (nchars - 4) );

  // Now we need to iterate from the most-significant character to the
  // last character written by the line tracing functions and copy these
  // characters into the given character array. So we are kind of
  // flipping the order of the characters due to the different between
  // how Verilog and C handle strings.

  int j = 0;
  for ( int i = nchars-1; i > nchar_last; i-- ) {
    char c = static_cast<char>( words[i/4] >> (8*(i%4)) );
    str[j] = c;
    j++;
  }
  str[j] = '\0';

}
#endif
