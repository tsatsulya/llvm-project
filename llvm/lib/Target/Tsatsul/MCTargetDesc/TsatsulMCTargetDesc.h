#ifndef LLVM_LIB_TARGET_TSATSUL_MCTARGETDESC_TSATSULMCTARGETDESC_H
#define LLVM_LIB_TARGET_TSATSUL_MCTARGETDESC_TSATSULMCTARGETDESC_H

// Defines symbolic names for Tsatsul registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "TsatsulGenRegisterInfo.inc"

// Defines symbolic names for the Tsatsul instructions.
#define GET_INSTRINFO_ENUM
#include "TsatsulGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_TSATSUL_MCTARGETDESC_TSATSULMCTARGETDESC_H
