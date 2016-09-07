/**
 * Last modified: Tue Aug 30 18:37:51 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"
#include "FontTypes.h"

namespace formulae {
namespace font {
charInfo_t charInfo(fontNr_t f, charCode_t ch);
dist_t charWidth(fontNr_t f, charCode_t ch);
dist_t charHeight(fontNr_t f, charCode_t ch);
dist_t charDepth(fontNr_t f, charCode_t ch);
dist_t charItalic(fontNr_t f, charCode_t ch);
optional<charCode_t> charLarger(fontNr_t f, charCode_t ch);

}
}

