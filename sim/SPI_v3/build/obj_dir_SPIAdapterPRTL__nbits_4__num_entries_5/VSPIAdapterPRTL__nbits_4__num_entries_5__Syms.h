// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VSPIADAPTERPRTL__NBITS_4__NUM_ENTRIES_5__SYMS_H_
#define _VSPIADAPTERPRTL__NBITS_4__NUM_ENTRIES_5__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VSPIAdapterPRTL__nbits_4__num_entries_5.h"
#include "VSPIAdapterPRTL__nbits_4__num_entries_5___024unit.h"

// SYMS CLASS
class VSPIAdapterPRTL__nbits_4__num_entries_5__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VSPIAdapterPRTL__nbits_4__num_entries_5* TOPp;
    
    // CREATORS
    VSPIAdapterPRTL__nbits_4__num_entries_5__Syms(VSPIAdapterPRTL__nbits_4__num_entries_5* topp, const char* namep);
    ~VSPIAdapterPRTL__nbits_4__num_entries_5__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
