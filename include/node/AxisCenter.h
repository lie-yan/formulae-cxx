#pragma once

#include "BasicTypes.h"
#include "BoxTypes.h"
#include "StyleParams.h"

namespace formulae{ namespace node {

template <typename Box = box_t> NodeRef axisCenter(style_t st, Box &&box) {
  auto axh = font::AxisHeight(st);
  auto h = box.height();
  auto d = box.depth();
  auto shift = half(h - d) - axh;
  return Box_t::create(std::forward<Box>(box), shift);
}}}