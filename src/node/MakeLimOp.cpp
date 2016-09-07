#include "MakeLimOp.h"

namespace formulae {
namespace node {

namespace MakeLimOp {
dist_t LimDist(std::function<dist_t(style_t)> distFun,
               std::function<dist_t(style_t)> posFun, style_t st,
               dist_t size) {
  return std::max(distFun(st), posFun(st) - size);
}

dist_t LimSupDist(style_t st, dist_t size) {
  return LimDist(font::BigOpSupDist, font::BigOpSupPos, st, size);
}

dist_t LimSubDist(style_t st, dist_t size) {
  return LimDist(font::BigOpSubDist, font::BigOpSubPos, st, size);
}

std::function<nlist_t(optional<box_t>)>
LimList(std::function<dist_t(style_t, dist_t)> distFun,
        std::function<dist_t(box_t)> sizeFun, style_t st,
        dist_t rightShift, dist_t w, dist_t pad) {
  auto emptyList = nlist_t();
  return general::optFold<box_t, nlist_t>(
      emptyList, [=](auto &&box) -> nlist_t {
        auto dist = distFun(st, sizeFun(box));
        auto k1 = Kern_t::create(dist);
        auto newBox = Box_t::create(rebox(w, std::forward<decltype(box)>(box)), rightShift);
        auto k2 = Kern_t::create(pad);
        return nlist_t{k1, std::move(newBox), k2};
      });
}

std::function<nlist_t(optional<box_t>)> SupList(style_t st,
                                                dist_t rightShift,
                                                dist_t w,
                                                dist_t pad) {
  return LimList(LimSupDist, std::mem_fn(&box_t::depth), st, rightShift, w,
                 pad);
}

std::function<nlist_t(optional<box_t>)> SubList(style_t st,
                                                dist_t rightShift,
                                                dist_t w,
                                                dist_t pad) {
  return LimList(LimSubDist, std::mem_fn(&box_t::height), st, rightShift, w,
                 pad);
}
}

} // namespace MakeLimOp
}