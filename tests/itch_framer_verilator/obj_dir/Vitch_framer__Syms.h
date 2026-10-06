// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VITCH_FRAMER__SYMS_H_
#define VERILATED_VITCH_FRAMER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vitch_framer.h"

// INCLUDE MODULE CLASSES
#include "Vitch_framer___024root.h"
#include "Vitch_framer_itch_framer.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vitch_framer__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vitch_framer* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vitch_framer___024root         TOP;
    Vitch_framer_itch_framer       TOP__itch_framer;

    // SCOPE NAMES
    VerilatedScope __Vscope_itch_framer;

    // CONSTRUCTORS
    Vitch_framer__Syms(VerilatedContext* contextp, const char* namep, Vitch_framer* modelp);
    ~Vitch_framer__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
