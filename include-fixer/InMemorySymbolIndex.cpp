//===-- InMemorySymbolIndex.cpp--------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "InMemorySymbolIndex.h"

using clang::find_all_symbols::SymbolInfo;

namespace clang {
namespace include_fixer {

InMemorySymbolIndex::InMemorySymbolIndex(
    const std::vector<SymbolInfo> &Symbols) {
  for (const auto &Symbol : Symbols)
    LookupTable[Symbol.getName()].push_back(Symbol);
}

std::vector<SymbolInfo>
InMemorySymbolIndex::search(llvm::StringRef Identifier) {
  auto I = LookupTable.find(Identifier);
  if (I != LookupTable.end())
    return I->second;
  return {};
}

} // namespace include_fixer
} // namespace clang
