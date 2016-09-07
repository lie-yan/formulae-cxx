#pragma once

#include "BoxPack.h"
#include "BoxTypes.h"
#include "MakeVBox.h"
#include "StyleParams.h"
namespace formulae {
namespace node {

namespace MakeLimOp {
dist_t LimDist(std::function<dist_t(style_t)> distFun,
               std::function<dist_t(style_t)> posFun, style_t st,
               dist_t size);

dist_t LimSupDist(style_t st, dist_t size);

dist_t LimSubDist(style_t st, dist_t size);

std::function<nlist_t(optional<box_t>)>
LimList(std::function<dist_t(style_t, dist_t)> distFun,
        std::function<dist_t(box_t)> sizeFun, style_t st,
        dist_t rightShift, dist_t w, dist_t pad);

std::function<nlist_t(optional<box_t>)> SupList(style_t st,
                                                dist_t rightShift,
                                                dist_t w,
                                                dist_t pad);

std::function<nlist_t(optional<box_t>)> SubList(style_t st,
                                                dist_t rightShift,
                                                dist_t w,
                                                dist_t pad);
}

template<typename Node = NodeRef, typename OptBox1 = optional<box_t>,
    typename OptBox2 = optional<box_t>>
box_t makeLimOp(style_t st, dist_t itCorr, Node &&nucNode,
                OptBox1 &&supOptBox, OptBox2 &&subOptBox) {
  using namespace MakeLimOp;
  auto nucBox = boxList(extend(itCorr, std::forward<Node>(nucNode)));
  auto optWidth =
      general::optFold<box_t, dist_t>(zero(), std::mem_fn(&box_t::width));
  auto list = {optWidth(supOptBox), nucBox.width(), optWidth(subOptBox)};
  auto w = *std::max_element(std::begin(list), std::end(list));
  auto pad = font::BigOpPadding(st);
  auto shift = half(itCorr);
  auto supList = SupList(st, shift, w, pad)(supOptBox);
  auto subList = SubList(st, -shift, w, pad)(subOptBox);
  auto nucItem = Box0(rebox(w, std::move(nucBox)));

  return makeVBox(w, nucItem, supList, subList);
}
} // namespace MakeLimO
}// p