#include "BasicChar.h"
#include "CharFunctions.h"
#include "CharInfo.h"


namespace formulae{
namespace node {

std::tuple<NodeRef, dist_t> basicChar(style_t st, bool enlarge, family_t fam,
                                     charCode_t ch) {
  auto fontNr = font::fontNumber(st, fam);
  auto ch1 = enlarge ? font::larger(fontNr, ch) : ch;
  return std::make_tuple(Char_t::create(fontNr, ch1), font::charItalic(fontNr, ch1));
}
}
}