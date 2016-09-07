/**
 * Last modified: Tue Aug 30 17:00:09 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */


#pragma once

#include "BasicTypes.h"
#include "Powers2.h"
#include <cfenv>
#include <cmath>

namespace formulae {

constexpr dist_t zero() { return dist_t{0}; }
constexpr dist_t one() { return dist_t{Powers2::two16}; }
constexpr dist_t half(dist_t d) { return d/2; }
constexpr dist_t distInt(int n) { return n * one(); }
constexpr dist_t distRat(int num, int den) { return num * one() / den; }
dist_t realMult(real_t r, dist_t d);
dist_t distReal(real_t r);

} // namespace formulae