#pragma once

#include "BasicTypes.h"
#include "BoxTypes.h"
#include "MakeVBox.h"
namespace formulae{ namespace node {

namespace MakeAtop {
dist_t atopMinDist(style_t st);

std::tuple<dist_t, dist_t> atopDistances(style_t st, dist_t dtop,
                                         dist_t hbot);
}
template <typename Box1 = box_t, typename Box2 = box_t>
NodeRef makeAtop(style_t st, Box1 &&topBox, Box2 &&botBox) {
  auto distances = MakeAtop::atopDistances(st, topBox.depth(), botBox.height());
  return above(Box0(std::forward<Box1>(topBox)), std::get<0>(distances),
               std::get<1>(distances), Box0(std::forward<Box2>(botBox)));
}}}