#include "MakeChar.h"
#include "BasicChar.h"
#include "BoxPack.h"
#include "AxisCenter.h"

namespace formulae{ namespace node {

hlist_t makeChar(style_t st, family_t fam, charCode_t ch) {
  NodeRef charNode;
  dist_t itCorr;
  std::tie(charNode, itCorr) = basicChar(st, false, fam, ch);
  return extend(itCorr, std::move(charNode));
}

std::tuple<NodeRef, dist_t, bool>
makeNucChar(style_t st, bool isOp, family_t fam, charCode_t ch) {
  auto enlarge = (isOp and (st == style_t::Display));
  NodeRef charNode;
  dist_t itCorr;
  std::tie(charNode, itCorr) = basicChar(st, enlarge, fam, ch);
  auto nucNode = isOp ? axisCenter(st, boxList(nlist_t{charNode})) : charNode;
  return std::make_tuple(nucNode, itCorr, not isOp);
}}}