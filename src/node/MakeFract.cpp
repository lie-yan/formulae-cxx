
#include "MakeFract.h"
#include "BasicBox.h"
#include "BasicTypes.h"
#include "BoxTypes.h"
#include "MakeVBox.h"
#include "StyleParams.h"
namespace formulae{ namespace node {

namespace MakeFract {

dist_t fractMinDist(style_t st, dist_t halfTh) {
  return (st == style_t::Display) ? (halfTh * 6) : (halfTh * 2);
}

std::tuple<dist_t, dist_t> distances(style_t st, dist_t axh,
                                     dist_t halfTh, dist_t dnum,
                                     dist_t hden) {
  auto axisNum = font::fractNum(st) - axh;
  auto axisDen = font::Denom(st) + axh;
  auto distNum = axisNum - halfTh - dnum;
  auto distDen = axisDen - halfTh - hden;
  auto correct = [&st, &halfTh](dist_t dist) {
    return std::max(dist, fractMinDist(st, halfTh));
  };
  return std::make_tuple(correct(distNum), correct(distDen));
};
}}}