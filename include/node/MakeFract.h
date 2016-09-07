#pragma once

#include "BasicBox.h"
#include "BasicTypes.h"
#include "BoxTypes.h"
#include "MakeVBox.h"
#include "StyleParams.h"
namespace formulae{ namespace node {


namespace MakeFract {
  
dist_t fractMinDist(style_t st, dist_t halfTh);
  

std::tuple<dist_t, dist_t> distances(style_t st, dist_t axh,
                                     dist_t halfTh, dist_t dnum,
                                     dist_t hden);
  
template <typename Box = box_t>
nlist_t makeList(dist_t dist, Box &&box) {
  return nlist_t{Kern_t::create(dist), Box0(std::forward<Box>(box))};
};
}

template <typename Box1 = box_t, typename Box2 = box_t>
NodeRef makeFract(style_t st, dist_t th, dist_t w,
                 Box1 &&numBox, Box2 &&denBox) {
  
  using namespace MakeFract;
  
  auto halfTh = half(th);
  auto axh    = font::AxisHeight(st);
  auto stroke = Rule_t::create(dim_t(w, halfTh, halfTh));
  dist_t distNum, distDen;
  std::tie(distNum, distDen) =
      distances(st, axh, halfTh, numBox.depth(), denBox.height());
  auto fractBox = makeVBox(w, stroke,
                           makeList(distNum, std::forward<Box1>(numBox)),
                           makeList(distDen, std::forward<Box2>(denBox)));
  return Box_t::create(std::move(fractBox), -axh);
};}}