#ifndef LLVM_LIB_TARGET_TSATSUL_TSATSULREGISTERINFO_H
#define LLVM_LIB_TARGET_TSATSUL_TSATSULREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "TsatsulGenRegisterInfo.inc"

namespace llvm {

class TargetInstrInfo;
class TsatsulSubtarget;

struct TsatsulRegisterInfo : public TsatsulGenRegisterInfo {
public:
  TsatsulRegisterInfo();

  const MCPhysReg *getCalleeSavedRegs(const MachineFunction *MF) const override;

  const uint32_t *getCallPreservedMask(const MachineFunction &MF,
                                       CallingConv::ID CC) const override;

  BitVector getReservedRegs(const MachineFunction &MF) const override;

  bool requiresRegisterScavenging(const MachineFunction &MF) const override;

  bool eliminateFrameIndex(MachineBasicBlock::iterator II, int SPAdj,
                           unsigned FIOperandNum,
                           RegScavenger *RS = nullptr) const override;

  // Debug information queries.
  Register getFrameRegister(const MachineFunction &MF) const override;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_TSATSUL_TSATSULREGISTERINFO_H