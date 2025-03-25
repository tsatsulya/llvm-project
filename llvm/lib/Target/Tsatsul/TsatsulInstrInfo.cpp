#include "TsatsulInstrInfo.h"
#include "Tsatsul.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "TsatsulGenInstrInfo.inc"

#define DEBUG_TYPE "Tsatsul-inst-info"

TsatsulInstrInfo::TsatsulInstrInfo() : TsatsulGenInstrInfo() { TSATSUL_DUMP_GREEN }
