/**
 *
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"

namespace formulae {
namespace font {

dist_t xHeight(style_t st);
dist_t MathUnit(style_t st);
dist_t atopNum(style_t st);
dist_t fractNum(style_t st);
dist_t Denom(style_t st);

dist_t Sup(bool b, style_t st);
dist_t SubAlone(style_t st);

dist_t SubWithSup(style_t st);
dist_t SupDrop(style_t st);
dist_t SubDrop(style_t st);

dist_t Delim(style_t st);
dist_t AxisHeight(style_t st);
dist_t RuleThickness(style_t st);
dist_t BigOpSupDist(style_t st);
dist_t BigOpSubDist(style_t st);
dist_t BigOpSupPos(style_t st);
dist_t BigOpSubPos(style_t st);
dist_t BigOpPadding(style_t st);
}
}