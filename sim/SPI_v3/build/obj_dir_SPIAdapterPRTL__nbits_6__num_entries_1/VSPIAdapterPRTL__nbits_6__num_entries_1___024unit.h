// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSPIAdapterPRTL__nbits_6__num_entries_1.h for the primary calling header

#ifndef _VSPIADAPTERPRTL__NBITS_6__NUM_ENTRIES_1___024UNIT_H_
#define _VSPIADAPTERPRTL__NBITS_6__NUM_ENTRIES_1___024UNIT_H_  // guard

#include "verilated.h"

//==========

class VSPIAdapterPRTL__nbits_6__num_entries_1__Syms;

//----------

VL_MODULE(VSPIAdapterPRTL__nbits_6__num_entries_1___024unit) {
  public:
    
    // INTERNAL VARIABLES
  private:
    VSPIAdapterPRTL__nbits_6__num_entries_1__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VSPIAdapterPRTL__nbits_6__num_entries_1___024unit);  ///< Copying not allowed
  public:
    VSPIAdapterPRTL__nbits_6__num_entries_1___024unit(const char* name = "TOP");
    ~VSPIAdapterPRTL__nbits_6__num_entries_1___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(VSPIAdapterPRTL__nbits_6__num_entries_1__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
