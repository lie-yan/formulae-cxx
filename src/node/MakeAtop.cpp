
#include "MakeAtop.h"
#include "BasicTypes.h"
#include "BoxTypes.h"
#include "MakeVBox.h"
#include "NodeDim.h"
#include "StyleParams.h"

namespace formulae{ namespace node {

namespace MakeAtop {
dist_t atopMinDist(style_t st) {
  return (st == style_t::Display) ? (font::RuleThickness(st) * 7)
                            : (font::RuleThickness(st) * 3);
}

std::tuple<dist_t, dist_t> atopDistances(style_t st, dist_t dtop,
                                         dist_t hbot) {
  auto distTop = font::atopNum(st) - dtop;
  auto distBot = font::Denom(st) - hbot;
  auto dist = distTop + distBot;
  auto minDist = atopMinDist(st);
  return (dist >= minDist)
             ? std::make_tuple(distTop, dist)
             : std::make_tuple(distTop + half(minDist - dist), minDist);
};
}}}