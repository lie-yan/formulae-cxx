/**
 * Last modified: Tue Aug 30 17:02:12 CST 2016 (outdated)
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"
#include "Distance.h"

namespace formulae {
namespace GV {

const int delimiterFactor = 901;// in units of 1000.
const dist_t delimiterShortfall = distReal(real_t{5.0});// 5.0 pt
const dist_t nullDelimiterSpace = distReal(real_t{1.2});// 1.2 pt
const dist_t scriptSpace = distReal(real_t{0.5});// 0.5 pt
const penalty_t infPenalty = penalty_t{10000};
const penalty_t relPenalty = penalty_t{500};
const penalty_t binopPenalty = penalty_t{700};
}
}