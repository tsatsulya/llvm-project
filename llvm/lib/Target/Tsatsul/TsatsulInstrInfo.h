#ifndef LLVM_LIB_TARGET_TSATSUL_TSATSULINSTRINFO_H
#define LLVM_LIB_TARGET_TSATSUL_TSATSULINSTRINFO_H

#include "TsatsulRegisterInfo.h"
#include "MCTargetDesc/TsatsulInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "TsatsulGenInstrInfo.inc"

namespace llvm {

class TsatsulSubtarget;

class TsatsulInstrInfo : public TsatsulGenInstrInfo {
public:
  TsatsulInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_TSATSUL_TSATSULINSTRINFO_H
