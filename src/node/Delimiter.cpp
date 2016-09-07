#include <node/BoxPack.h>
#include <node/BasicChar.h>
#include <node/AxisCenter.h>
#include <node/MakeVBox.h>
#include "Delimiter.h"
#include "Const.h"

namespace formulae {
namespace node {

charCode_t getExCharCode(charCode_t ch) {
  if (ch.value() == '(')
    return charCode_t{0};
  else if (ch.value() == ')')
    return charCode_t{1};
  else
    throw NotImplemented{};
}

std::tuple<NodeRef, bool> getLargerDelimiter(style_t st, bool larger, charCode_t ch) {
  NodeRef node;
  std::tie(node, std::ignore) = basicChar(st, larger, family_t::EX, ch);
  bool hasLarger = (node.as<Char_t>().charCode != ch);

  return std::make_tuple(node, hasLarger);
}

NodeRef varDelimiter(style_t st, dist_t delimiterSize, delim_t delim) {
  if (delim == delim_t(0))
    return Kern_t::create(GV::nullDelimiterSpace);
  else{

    /*--------------------------improve this part-----------------------------*/
    charCode_t ch = getExCharCode(delim.to<charCode_t>());
    NodeRef node; bool hasLarger;
    std::tie(node, hasLarger) = getLargerDelimiter(st, false, ch);
    for ( hasLarger = true; node.vsize() < delimiterSize and hasLarger; ) {
      std::tie(node, hasLarger) = getLargerDelimiter(st, true, node.as<Char_t>().charCode);
    }

    if (not hasLarger) {
      auto hl = hlist_t{node};
      std::tie(node, std::ignore) = getLargerDelimiter(st, false, node.as<Char_t>().charCode+charCode_t{16});
      hl.push_back(node);
      auto box = above(hl[0],zero(), zero(), hl[1]);
      auto centeredBox = axisCenter(st, box.as<Box_t>().box);
      return centeredBox;
    } else {
      auto box = boxList(hlist_t{node});
      auto centeredBox = axisCenter(st, box);
      return centeredBox;
    }
  }
}

NodeRef makeDelimiter(style_t st, delim_t delim) {
  return varDelimiter(st, font::Delim(st), delim);
}
}
}