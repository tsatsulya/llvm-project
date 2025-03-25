#include "TsatsulRegisterInfo.h"
#include "Tsatsul.h"
#include "TsatsulFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "TsatsulGenRegisterInfo.inc"

TsatsulRegisterInfo::TsatsulRegisterInfo() : TsatsulGenRegisterInfo(Tsatsul::R0) {
  TSATSUL_DUMP_GREEN
}
const MCPhysReg *
TsatsulRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  TSATSUL_DUMP_GREEN
  return CSR_Tsatsul_SaveList;
}

BitVector TsatsulRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  TSATSUL_DUMP_GREEN
  TsatsulFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(Tsatsul::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(Tsatsul::R2);
  }
  return Reserved;
}

bool TsatsulRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool TsatsulRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  TSATSUL_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register TsatsulRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  TSATSUL_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? Tsatsul::R2 : Tsatsul::R1;
}

const uint32_t *
TsatsulRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  TSATSUL_DUMP_GREEN
  return CSR_Tsatsul_RegMask;
}
