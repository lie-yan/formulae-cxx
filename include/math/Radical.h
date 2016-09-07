/**
 * Last modified: Tue Aug 30 19:55:56 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"
#include "BoxTypes.h"

namespace formulae {
namespace math {

template<typename Box = node::box_t>
node::box_t makeRadical(style_t st, delim_t del, Box &&box) {
  throw NotImplemented{"makeRadical(...) not implemented"};
}
}
}