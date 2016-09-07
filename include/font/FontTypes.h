/**
 * Last modified: Tue Aug 30 17:09:15 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"
#include "General.h"
#include <vector>

namespace formulae {

enum class FontTypeTag {
  fontNr = 7654,
};

using fontNr_t = grund::Unit<int(FontTypeTag::fontNr), int>;

struct varCharInfo_t {
  optional<charCode_t> top;
  optional<charCode_t> bot;
  optional<charCode_t> rep;
};

struct charInfo_t {
  dist_t width;
  dist_t height;
  dist_t depth;
  dist_t itCorr; // italic correction
  optional<charCode_t> larger;
  optional<varCharInfo_t> varChar;
};

using font_t = std::vector<charInfo_t>;

} // namespace formulae