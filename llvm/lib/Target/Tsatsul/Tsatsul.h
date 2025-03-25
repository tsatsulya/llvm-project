#ifndef LLVM_LIB_TARGET_Tsatsul_Tsatsul_H
#define LLVM_LIB_TARGET_Tsatsul_Tsatsul_H

#include "MCTargetDesc/TsatsulMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define TSATSUL_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define TSATSUL_DUMP(Color) {}

#define TSATSUL_DUMP_RED TSATSUL_DUMP(llvm::raw_ostream::RED)
#define TSATSUL_DUMP_GREEN TSATSUL_DUMP(llvm::raw_ostream::GREEN)
#define TSATSUL_DUMP_YELLOW TSATSUL_DUMP(llvm::raw_ostream::YELLOW)
#define TSATSUL_DUMP_CYAN TSATSUL_DUMP(llvm::raw_ostream::CYAN)
#define TSATSUL_DUMP_MAGENTA TSATSUL_DUMP(llvm::raw_ostream::MAGENTA)
#define TSATSUL_DUMP_WHITE TSATSUL_DUMP(llvm::raw_ostream::WHITE)
namespace llvm {
class TsatsulTargetMachine;
class FunctionPass;
class TsatsulSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerTsatsulMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                  AsmPrinter &AP);
bool LowerTsatsulMachineOperandToMCOperand(const MachineOperand &MO,
                                       MCOperand &MCOp, const AsmPrinter &AP);
FunctionPass *createTsatsulISelDag(TsatsulTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_Tsatsul_Tsatsul_H