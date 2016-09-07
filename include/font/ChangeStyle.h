/**
 * Last modified: Tue Aug 30 19:43:05 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"

namespace formulae {
namespace font {

style_t fract(style_t st);  // return the corresponding style for numerator/denominator
style_t script(style_t st); // return the corresponding style for script
}
}