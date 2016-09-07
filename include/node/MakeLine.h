#pragma once

#include "BasicBox.h"
#include "BasicTypes.h"
#include "BoxTypes.h"
#include "MakeVBox.h"
#include "StyleParams.h"

namespace formulae{ namespace node {

namespace MakeLine {
inline dist_t lineDist(style_t st) {
  return font::RuleThickness(st) * 3;
}
inline dist_t linePad(style_t st) { return font::RuleThickness(st); }
}
template <typename Box = box_t> box_t makeOver(style_t st, Box &&box) {
  using namespace MakeLine;
  auto w = box.width();
  auto line = rule(font::RuleThickness(st), w);
  return upVBox(
      w, std::forward<Box>(box),
      nlist_t{Kern_t::create(lineDist(st)), std::move(line), Kern_t::create(linePad(st))});
}

template <typename Box = box_t> box_t makeUnder(style_t st, Box &&box) {
  using namespace MakeLine;
  auto w = box.width();
  auto line = rule(font::RuleThickness(st), w);
  return dnVBox(
      w, std::forward<Box>(box),
      nlist_t{Kern_t::create(lineDist(st)), std::move(line), Kern_t::create(linePad(st))});
}}}