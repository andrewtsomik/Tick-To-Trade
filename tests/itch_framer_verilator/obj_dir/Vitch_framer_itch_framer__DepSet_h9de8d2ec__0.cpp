// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vitch_framer.h for the primary calling header

#include "Vitch_framer__pch.h"
#include "Vitch_framer__Syms.h"
#include "Vitch_framer_itch_framer.h"

VL_INLINE_OPT void Vitch_framer_itch_framer___ico_sequent__TOP__itch_framer__0(Vitch_framer_itch_framer* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vitch_framer_itch_framer___ico_sequent__TOP__itch_framer__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__next_state = vlSelfRef.state;
    if (vlSymsp->TOP.end_of_boundary) {
        vlSelfRef.__PVT__next_state = 0U;
    } else if ((4U & (IData)(vlSelfRef.state))) {
        if ((2U & (IData)(vlSelfRef.state))) {
            vlSelfRef.__PVT__next_state = 0U;
        } else if ((1U & (IData)(vlSelfRef.state))) {
            vlSelfRef.__PVT__next_state = 0U;
        } else if (vlSymsp->TOP.end_of_boundary) {
            vlSelfRef.__PVT__next_state = 0U;
        }
    } else if ((2U & (IData)(vlSelfRef.state))) {
        if ((1U & (IData)(vlSelfRef.state))) {
            if (((IData)(vlSymsp->TOP.itch_valid) & 
                 (1U == (IData)(vlSelfRef.bytes_remaining)))) {
                vlSelfRef.__PVT__next_state = ((1U 
                                                < (IData)(vlSelfRef.__PVT__messages_remaining))
                                                ? 2U
                                                : 4U);
            }
        } else if (((IData)(vlSymsp->TOP.itch_valid) 
                    & (IData)(vlSelfRef.__PVT__length_idx))) {
            vlSelfRef.__PVT__next_state = 3U;
        }
    } else if ((1U & (IData)(vlSelfRef.state))) {
        if (vlSelfRef.__PVT__message_count_ready) {
            vlSelfRef.__PVT__next_state = (((0U == (IData)(vlSelfRef.__PVT__message_count)) 
                                            | (0xffffU 
                                               == (IData)(vlSelfRef.__PVT__message_count)))
                                            ? 4U : 2U);
        }
    } else if (vlSymsp->TOP.start_of_boundary) {
        vlSelfRef.__PVT__next_state = 1U;
    }
    vlSelfRef.valid = ((IData)(vlSymsp->TOP.itch_valid) 
                       & (3U == (IData)(vlSelfRef.state)));
}

VL_INLINE_OPT void Vitch_framer_itch_framer___nba_sequent__TOP__itch_framer__0(Vitch_framer_itch_framer* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vitch_framer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+  Vitch_framer_itch_framer___nba_sequent__TOP__itch_framer__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __Vdly__itch_idx;
    __Vdly__itch_idx = 0;
    SData/*15:0*/ __Vdly__message_length;
    __Vdly__message_length = 0;
    CData/*0:0*/ __Vdly__length_idx;
    __Vdly__length_idx = 0;
    SData/*15:0*/ __Vdly__message_count;
    __Vdly__message_count = 0;
    CData/*0:0*/ __Vdly__message_count_ready;
    __Vdly__message_count_ready = 0;
    SData/*15:0*/ __Vdly__bytes_remaining;
    __Vdly__bytes_remaining = 0;
    SData/*15:0*/ __Vdly__messages_remaining;
    __Vdly__messages_remaining = 0;
    // Body
    __Vdly__itch_idx = vlSelfRef.__PVT__itch_idx;
    __Vdly__message_count_ready = vlSelfRef.__PVT__message_count_ready;
    __Vdly__message_count = vlSelfRef.__PVT__message_count;
    __Vdly__message_length = vlSelfRef.__PVT__message_length;
    __Vdly__length_idx = vlSelfRef.__PVT__length_idx;
    __Vdly__messages_remaining = vlSelfRef.__PVT__messages_remaining;
    __Vdly__bytes_remaining = vlSelfRef.bytes_remaining;
    if ((1U & ((~ (IData)(vlSymsp->TOP.rst_n)) | (IData)(vlSymsp->TOP.end_of_boundary)))) {
        __Vdly__itch_idx = 0U;
        __Vdly__message_count_ready = 0U;
        __Vdly__message_count = 0U;
        __Vdly__message_length = 0U;
        __Vdly__length_idx = 0U;
        __Vdly__bytes_remaining = 0U;
        __Vdly__messages_remaining = 0U;
    } else if (vlSymsp->TOP.itch_valid) {
        if ((1U == (IData)(vlSelfRef.state))) {
            __Vdly__itch_idx = (0x1fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.__PVT__itch_idx)));
        }
        if ((1U & (~ ((0x12U == (IData)(vlSelfRef.__PVT__itch_idx)) 
                      & (1U == (IData)(vlSelfRef.state)))))) {
            if (((0x13U == (IData)(vlSelfRef.__PVT__itch_idx)) 
                 & (1U == (IData)(vlSelfRef.state)))) {
                __Vdly__message_count_ready = 1U;
            } else if (vlSelfRef.__PVT__message_count_ready) {
                __Vdly__message_count_ready = 0U;
            }
        }
        if (((0x12U == (IData)(vlSelfRef.__PVT__itch_idx)) 
             & (1U == (IData)(vlSelfRef.state)))) {
            __Vdly__message_count = vlSymsp->TOP.itch_byte;
        } else if (((0x13U == (IData)(vlSelfRef.__PVT__itch_idx)) 
                    & (1U == (IData)(vlSelfRef.state)))) {
            __Vdly__message_count = ((0xff00U & ((IData)(vlSelfRef.__PVT__message_count) 
                                                 << 8U)) 
                                     | (IData)(vlSymsp->TOP.itch_byte));
        }
        if (((IData)(vlSelfRef.__PVT__message_count_ready) 
             | ((2U == (IData)(vlSelfRef.state)) & 
                (~ (IData)(vlSelfRef.__PVT__length_idx))))) {
            __Vdly__message_length = vlSymsp->TOP.itch_byte;
            __Vdly__length_idx = 1U;
        } else if (((2U == (IData)(vlSelfRef.state)) 
                    & (IData)(vlSelfRef.__PVT__length_idx))) {
            __Vdly__message_length = ((0xff00U & ((IData)(vlSelfRef.__PVT__message_length) 
                                                  << 8U)) 
                                      | (IData)(vlSymsp->TOP.itch_byte));
            __Vdly__length_idx = 0U;
        }
        if (vlSelfRef.__PVT__message_count_ready) {
            __Vdly__messages_remaining = vlSelfRef.__PVT__message_count;
        } else if (((3U == (IData)(vlSelfRef.state)) 
                    & (1U == (IData)(vlSelfRef.bytes_remaining)))) {
            __Vdly__messages_remaining = (0xffffU & 
                                          ((IData)(vlSelfRef.__PVT__messages_remaining) 
                                           - (IData)(1U)));
        }
        if (((2U == (IData)(vlSelfRef.state)) & (IData)(vlSelfRef.__PVT__length_idx))) {
            __Vdly__bytes_remaining = ((0xff00U & ((IData)(vlSelfRef.__PVT__message_length) 
                                                   << 8U)) 
                                       | (IData)(vlSymsp->TOP.itch_byte));
        } else if ((3U == (IData)(vlSelfRef.state))) {
            __Vdly__bytes_remaining = (0xffffU & ((IData)(vlSelfRef.bytes_remaining) 
                                                  - (IData)(1U)));
        }
    }
    vlSelfRef.__PVT__itch_idx = __Vdly__itch_idx;
    vlSelfRef.__PVT__message_length = __Vdly__message_length;
    vlSelfRef.__PVT__messages_remaining = __Vdly__messages_remaining;
    vlSelfRef.__PVT__message_count = __Vdly__message_count;
    vlSelfRef.__PVT__length_idx = __Vdly__length_idx;
    vlSelfRef.__PVT__message_count_ready = __Vdly__message_count_ready;
    vlSelfRef.bytes_remaining = __Vdly__bytes_remaining;
    vlSelfRef.state = ((IData)(vlSymsp->TOP.rst_n) ? (IData)(vlSelfRef.__PVT__next_state)
                        : 0U);
    vlSelfRef.__PVT__next_state = vlSelfRef.state;
    if (vlSymsp->TOP.end_of_boundary) {
        vlSelfRef.__PVT__next_state = 0U;
    } else if ((4U & (IData)(vlSelfRef.state))) {
        if ((2U & (IData)(vlSelfRef.state))) {
            vlSelfRef.__PVT__next_state = 0U;
        } else if ((1U & (IData)(vlSelfRef.state))) {
            vlSelfRef.__PVT__next_state = 0U;
        } else if (vlSymsp->TOP.end_of_boundary) {
            vlSelfRef.__PVT__next_state = 0U;
        }
    } else if ((2U & (IData)(vlSelfRef.state))) {
        if ((1U & (IData)(vlSelfRef.state))) {
            if (((IData)(vlSymsp->TOP.itch_valid) & 
                 (1U == (IData)(vlSelfRef.bytes_remaining)))) {
                vlSelfRef.__PVT__next_state = ((1U 
                                                < (IData)(vlSelfRef.__PVT__messages_remaining))
                                                ? 2U
                                                : 4U);
            }
        } else if (((IData)(vlSymsp->TOP.itch_valid) 
                    & (IData)(vlSelfRef.__PVT__length_idx))) {
            vlSelfRef.__PVT__next_state = 3U;
        }
    } else if ((1U & (IData)(vlSelfRef.state))) {
        if (vlSelfRef.__PVT__message_count_ready) {
            vlSelfRef.__PVT__next_state = (((0U == (IData)(vlSelfRef.__PVT__message_count)) 
                                            | (0xffffU 
                                               == (IData)(vlSelfRef.__PVT__message_count)))
                                            ? 4U : 2U);
        }
    } else if (vlSymsp->TOP.start_of_boundary) {
        vlSelfRef.__PVT__next_state = 1U;
    }
    vlSelfRef.valid = ((IData)(vlSymsp->TOP.itch_valid) 
                       & (3U == (IData)(vlSelfRef.state)));
}
