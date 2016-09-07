/**
 * Last modified: Tue Aug 30 17:00:09 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "Distance.h"
namespace formulae {

dist_t realMult(real_t r, dist_t d) {
  auto ret = std::round(r.value() * d.value());
  return dist_t{static_cast<dist_t::intrinsic_type>(ret)};
}

dist_t distReal(real_t r) { return realMult(r, one()); }
}