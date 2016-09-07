/**
 *
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */


#pragma once

#include "BasicTypes.h"
#include "FontTypes.h"

/**
 * Idea: famFont will compute a font number from family and style.
 * This number is used to look up the font in fontVector.
 * Vector fontVector is built from the repetition free list famSizePairs
 * which enumerates all possibly needed pairs (family, size in pt).
 * Function number computes this repetition free list,
 * and the font numbers to index it.
 */

namespace formulae {

using famStylePair_t = std::tuple<family_t, style_t>;
using famSizePair_t  = std::tuple<family_t, fsize_t>;

template<typename X, typename Y>
list_t<std::tuple<X, Y>> prod(list_t<X> xl, list_t<Y> yl) {
  list_t<std::tuple<X, Y>> ret;
  for (const auto &x : xl)
    for (const auto &y : yl)
      ret.push_back(std::make_tuple(x, y));
  return ret;
};

namespace GV {
extern std::vector<famSizePair_t> famSizeVector;
extern std::vector<fontNr_t> fontNumberVector;
extern std::vector<font_t> fontVector;
}

}