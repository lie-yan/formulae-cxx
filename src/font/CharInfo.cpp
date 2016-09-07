/**
 * Last modified: Tue Aug 30 18:37:51 CST 2016

 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "CharInfo.h"
#include "FontVector.h"

namespace formulae {
namespace font {

charInfo_t charInfo(fontNr_t f, charCode_t ch) {
  return GV::fontVector[f.value()][ch.value()];
}
dist_t charWidth(fontNr_t f, charCode_t ch) {
  return charInfo(f, ch).width;
}
dist_t charHeight(fontNr_t f, charCode_t ch) {
  return charInfo(f, ch).height;
}
dist_t charDepth(fontNr_t f, charCode_t ch) {
  return charInfo(f, ch).depth;
}
dist_t charItalic(fontNr_t f, charCode_t ch) {
  return charInfo(f, ch).itCorr;
}
optional<charCode_t> charLarger(fontNr_t f, charCode_t ch) {
  return charInfo(f, ch).larger;
}
}
}