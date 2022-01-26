// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSPIAdapterPRTL__nbits_4__num_entries_5.h for the primary calling header

#include "VSPIAdapterPRTL__nbits_4__num_entries_5.h"
#include "VSPIAdapterPRTL__nbits_4__num_entries_5__Syms.h"

//==========

void VSPIAdapterPRTL__nbits_4__num_entries_5::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSPIAdapterPRTL__nbits_4__num_entries_5::eval\n"); );
    VSPIAdapterPRTL__nbits_4__num_entries_5__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VSPIAdapterPRTL__nbits_4__num_entries_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("SPIAdapterPRTL__nbits_4__num_entries_5__pickled.v", 321, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VSPIAdapterPRTL__nbits_4__num_entries_5::_eval_initial_loop(VSPIAdapterPRTL__nbits_4__num_entries_5__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("SPIAdapterPRTL__nbits_4__num_entries_5__pickled.v", 321, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VSPIAdapterPRTL__nbits_4__num_entries_5::_combo__TOP__1(VSPIAdapterPRTL__nbits_4__num_entries_5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPIAdapterPRTL__nbits_4__num_entries_5::_combo__TOP__1\n"); );
    VSPIAdapterPRTL__nbits_4__num_entries_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf___05Fwdata[0U] 
        = vlTOPp->recv___05Fmsg;
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf___05Fwdata[0U] 
        = (3U & (IData)(vlTOPp->push___05Fmsg));
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_recv_val 
        = (((IData)(vlTOPp->push___05Fmsg) >> 3U) & (IData)(vlTOPp->push___05Fen));
}

VL_INLINE_OPT void VSPIAdapterPRTL__nbits_4__num_entries_5::_sequent__TOP__3(VSPIAdapterPRTL__nbits_4__num_entries_5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPIAdapterPRTL__nbits_4__num_entries_5::_sequent__TOP__3\n"); );
    VSPIAdapterPRTL__nbits_4__num_entries_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*2:0*/ __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__head;
    CData/*2:0*/ __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__tail;
    CData/*2:0*/ __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl___05Fcount;
    CData/*2:0*/ __Vdlyvdim0__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT__regs__v0;
    CData/*1:0*/ __Vdlyvval__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT__regs__v0;
    CData/*0:0*/ __Vdlyvset__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT__regs__v0;
    CData/*2:0*/ __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__head;
    CData/*2:0*/ __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__tail;
    CData/*2:0*/ __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount;
    CData/*2:0*/ __Vdlyvdim0__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT__regs__v0;
    CData/*1:0*/ __Vdlyvval__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT__regs__v0;
    CData/*0:0*/ __Vdlyvset__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT__regs__v0;
    // Body
    __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__tail 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__tail;
    __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__tail 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__tail;
    __Vdlyvset__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT__regs__v0 = 0U;
    __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl___05Fcount 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl___05Fcount;
    __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount;
    __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__head 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__head;
    __Vdlyvset__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT__regs__v0 = 0U;
    __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__head 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__head;
    if (vlTOPp->reset) {
        __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__tail = 0U;
    } else {
        if (vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__recv_xfer) {
            __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__tail 
                = ((4U > (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__tail))
                    ? (7U & ((IData)(1U) + (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__tail)))
                    : 0U);
        }
    }
    if (vlTOPp->reset) {
        __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__tail = 0U;
    } else {
        if (vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__recv_xfer) {
            __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__tail 
                = ((4U > (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__tail))
                    ? (7U & ((IData)(1U) + (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__tail)))
                    : 0U);
        }
    }
    if (vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT____Vcellinp__rf__wen
        [0U]) {
        vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT____Vlvbound2 
            = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT____Vcellinp__rf__wdata
            [0U];
        if ((4U >= vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT____Vcellinp__rf__waddr
             [0U])) {
            __Vdlyvval__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT__regs__v0 
                = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT____Vlvbound2;
            __Vdlyvset__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT__regs__v0 = 1U;
            __Vdlyvdim0__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT__regs__v0 
                = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT____Vcellinp__rf__waddr
                [0U];
        }
    }
    if (vlTOPp->reset) {
        __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl___05Fcount = 0U;
    } else {
        if (((IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__recv_xfer) 
             & (~ (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__send_xfer)))) {
            __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl___05Fcount 
                = (7U & ((IData)(1U) + (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl___05Fcount)));
        } else {
            if (((~ (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__recv_xfer)) 
                 & (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__send_xfer))) {
                __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl___05Fcount 
                    = (7U & ((IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl___05Fcount) 
                             - (IData)(1U)));
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount = 0U;
    } else {
        if (((IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__recv_xfer) 
             & (~ (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__send_xfer)))) {
            __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount 
                = (7U & ((IData)(1U) + (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount)));
        } else {
            if (((~ (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__recv_xfer)) 
                 & (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__send_xfer))) {
                __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount 
                    = (7U & ((IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount) 
                             - (IData)(1U)));
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__head = 0U;
    } else {
        if (vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__send_xfer) {
            __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__head 
                = ((4U > (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__head))
                    ? (7U & ((IData)(1U) + (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__head)))
                    : 0U);
        }
    }
    if (vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT____Vcellinp__rf__wen
        [0U]) {
        vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT____Vlvbound2 
            = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT____Vcellinp__rf__wdata
            [0U];
        if ((4U >= vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT____Vcellinp__rf__waddr
             [0U])) {
            __Vdlyvval__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT__regs__v0 
                = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT____Vlvbound2;
            __Vdlyvset__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT__regs__v0 = 1U;
            __Vdlyvdim0__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT__regs__v0 
                = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT____Vcellinp__rf__waddr
                [0U];
        }
    }
    if (vlTOPp->reset) {
        __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__head = 0U;
    } else {
        if (vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__send_xfer) {
            __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__head 
                = ((4U > (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__head))
                    ? (7U & ((IData)(1U) + (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__head)))
                    : 0U);
        }
    }
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__tail 
        = __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__tail;
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__tail 
        = __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__tail;
    if (__Vdlyvset__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT__regs__v0) {
        vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT__regs[__Vdlyvdim0__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT__regs__v0] 
            = __Vdlyvval__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT__regs__v0;
    }
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl___05Fcount 
        = __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl___05Fcount;
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount 
        = __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount;
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__head 
        = __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__head;
    if (__Vdlyvset__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT__regs__v0) {
        vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT__regs[__Vdlyvdim0__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT__regs__v0] 
            = __Vdlyvval__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT__regs__v0;
    }
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__head 
        = __Vdly__SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__head;
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf___05Fwaddr[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__tail;
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf___05Fwaddr[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__tail;
    vlTOPp->recv___05Frdy = (5U > (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl___05Fcount));
    vlTOPp->send___05Fval = (0U < (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount));
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf___05Fraddr[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__head;
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf___05Fraddr[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__head;
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT____Vcellinp__rf__waddr[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf___05Fwaddr
        [0U];
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT____Vcellinp__rf__waddr[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf___05Fwaddr
        [0U];
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT____Vcellinp__rf__raddr[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf___05Fraddr
        [0U];
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT____Vcellinp__rf__raddr[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf___05Fraddr
        [0U];
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT____Vlvbound1 
        = ((4U >= vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT____Vcellinp__rf__raddr
            [0U]) ? vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT__regs
           [vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT____Vcellinp__rf__raddr
           [0U]] : 0U);
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT____Vcellout__rf__rdata[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf__DOT____Vlvbound1;
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT____Vlvbound1 
        = ((4U >= vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT____Vcellinp__rf__raddr
            [0U]) ? vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT__regs
           [vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT____Vcellinp__rf__raddr
           [0U]] : 0U);
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT____Vcellout__rf__rdata[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf__DOT____Vlvbound1;
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf___05Frdata[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT____Vcellout__rf__rdata
        [0U];
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf___05Frdata[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT____Vcellout__rf__rdata
        [0U];
    vlTOPp->send___05Fmsg = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf___05Frdata
        [0U];
}

VL_INLINE_OPT void VSPIAdapterPRTL__nbits_4__num_entries_5::_combo__TOP__4(VSPIAdapterPRTL__nbits_4__num_entries_5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPIAdapterPRTL__nbits_4__num_entries_5::_combo__TOP__4\n"); );
    VSPIAdapterPRTL__nbits_4__num_entries_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT____Vcellinp__rf__wdata[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf___05Fwdata
        [0U];
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT____Vcellinp__rf__wdata[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf___05Fwdata
        [0U];
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__recv_xfer 
        = ((IData)(vlTOPp->recv___05Fval) & (5U > (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl___05Fcount)));
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__send_xfer 
        = ((0U < (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount)) 
           & (IData)(vlTOPp->send___05Frdy));
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__recv_xfer 
        = ((IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_recv_val) 
           & (5U > (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount)));
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__open_entries 
        = (4U > (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount));
    vlTOPp->pull___05Fmsg = ((0xbU & (IData)(vlTOPp->pull___05Fmsg)) 
                             | (((5U > (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl___05Fcount)) 
                                 & ((~ (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_recv_val)) 
                                    | (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__open_entries))) 
                                << 2U));
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_send_rdy 
        = (((IData)(vlTOPp->push___05Fmsg) >> 2U) & (IData)(vlTOPp->pull___05Fen));
    vlTOPp->pull___05Fmsg = ((7U & (IData)(vlTOPp->pull___05Fmsg)) 
                             | (((IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_send_rdy) 
                                 & (0U < (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl___05Fcount))) 
                                << 3U));
    vlTOPp->pull___05Fmsg = ((0xcU & (IData)(vlTOPp->pull___05Fmsg)) 
                             | (vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf___05Frdata
                                [0U] & ((2U & ((IData)(vlTOPp->pull___05Fmsg) 
                                               >> 2U)) 
                                        | (1U & ((IData)(vlTOPp->pull___05Fmsg) 
                                                 >> 3U)))));
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf___05Fwen[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__recv_xfer;
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf___05Fwen[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__ctrl__DOT__recv_xfer;
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl__DOT__send_xfer 
        = ((0U < (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__ctrl___05Fcount)) 
           & (IData)(vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_send_rdy));
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT____Vcellinp__rf__wen[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__cm_q__DOT__dpath__DOT__rf___05Fwen
        [0U];
    vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT____Vcellinp__rf__wen[0U] 
        = vlTOPp->SPIAdapterPRTL___05Fnbits_4___05Fnum_entries_5__DOT__mc_q__DOT__dpath__DOT__rf___05Fwen
        [0U];
}

void VSPIAdapterPRTL__nbits_4__num_entries_5::_eval(VSPIAdapterPRTL__nbits_4__num_entries_5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPIAdapterPRTL__nbits_4__num_entries_5::_eval\n"); );
    VSPIAdapterPRTL__nbits_4__num_entries_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData VSPIAdapterPRTL__nbits_4__num_entries_5::_change_request(VSPIAdapterPRTL__nbits_4__num_entries_5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPIAdapterPRTL__nbits_4__num_entries_5::_change_request\n"); );
    VSPIAdapterPRTL__nbits_4__num_entries_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VSPIAdapterPRTL__nbits_4__num_entries_5::_change_request_1(VSPIAdapterPRTL__nbits_4__num_entries_5__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPIAdapterPRTL__nbits_4__num_entries_5::_change_request_1\n"); );
    VSPIAdapterPRTL__nbits_4__num_entries_5* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VSPIAdapterPRTL__nbits_4__num_entries_5::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSPIAdapterPRTL__nbits_4__num_entries_5::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((pull___05Fen & 0xfeU))) {
        Verilated::overWidthError("pull__en");}
    if (VL_UNLIKELY((push___05Fen & 0xfeU))) {
        Verilated::overWidthError("push__en");}
    if (VL_UNLIKELY((recv___05Fmsg & 0xfcU))) {
        Verilated::overWidthError("recv__msg");}
    if (VL_UNLIKELY((recv___05Fval & 0xfeU))) {
        Verilated::overWidthError("recv__val");}
    if (VL_UNLIKELY((send___05Frdy & 0xfeU))) {
        Verilated::overWidthError("send__rdy");}
}
#endif  // VL_DEBUG
