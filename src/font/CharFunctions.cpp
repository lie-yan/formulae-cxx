/**
 * Last modified: Tue Aug 30 18:52:03 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "CharFunctions.h"
#include "FontVector.h"
#include "CharInfo.h"
#include "General.h"

namespace formulae {
namespace font {

fontNr_t fontNumber(style_t st, family_t fam) {
  return GV::fontNumberVector[4 * famNr(fam) + styleNr(st)];
}
charCode_t larger(fontNr_t f, charCode_t ch) {
  return general::optVal(ch)(charLarger(f, ch));
}
}
}
