#ifndef LLVM_LIB_TARGET_TSATSUL_MCTARGETDESC_TSATSULINFO_H
#define LLVM_LIB_TARGET_TSATSUL_MCTARGETDESC_TSATSULINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace TsatsulOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace TsatsulOp

} // end namespace llvm

#endif
