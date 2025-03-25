add_llvm_component_library(LLVMTsatsulInfo
  TsatsulTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Tsatsul
  )
