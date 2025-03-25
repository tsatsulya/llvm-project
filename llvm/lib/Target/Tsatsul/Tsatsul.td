include "llvm/Target/Target.td"
include "TsatsulRegisterInfo.td"
include "TsatsulInstrInfo.td"
include "TsatsulCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def TsatsulInstrInfo : InstrInfo;
def Tsatsul : Target {
  let InstructionSet = TsatsulInstrInfo;
}
