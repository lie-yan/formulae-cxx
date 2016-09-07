/**
 * Created: Wed Aug 31 11:28:44 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */
#pragma once

#include "MathTypes.h"

namespace formulae {
namespace math {

namespace MathGlue {
using namespace node;
using subSpec = glueSpec_t::subSpec_t;

const subSpec zeropair = subSpec{dist_t(0), infOrder_t::normal};
const SGlue_t thinGlue = SGlue_t{glueSpec_t{dist_t(3), zeropair, zeropair}};

const SGlue_t medGlue = SGlue_t{glueSpec_t{dist_t(4),
                                           subSpec{dist_t(2), infOrder_t::normal},
                                           subSpec{dist_t(4), infOrder_t::normal}}};

const SGlue_t thickGlue = SGlue_t{glueSpec_t{dist_t(5),
                                             subSpec{dist_t(5), infOrder_t::normal},
                                             zeropair}};

inline optional <mathSpace_t> space(bool always, const SpaceRef &g) {
  return optional<mathSpace_t>(mathSpace_t{true, always, g});
}
inline optional <mathSpace_t> allstyles(const SpaceRef &g) { return space(true, g); }
inline optional <mathSpace_t> nonscript(const SpaceRef &g) { return space(false, g); }
}//namespace MathGlue

const optional <mathSpace_t> noSkip = optional<mathSpace_t>();
const optional <mathSpace_t> thinSkip = MathGlue::allstyles(MathGlue::thinGlue);
const optional <mathSpace_t> medSkip = MathGlue::allstyles(MathGlue::medGlue);
const optional <mathSpace_t> thickSkip = MathGlue::allstyles(MathGlue::thickGlue);
const optional <mathSpace_t> thinSkip1 = MathGlue::nonscript(MathGlue::thinGlue);
const optional <mathSpace_t> medSkip1 = MathGlue::nonscript(MathGlue::medGlue);
const optional <mathSpace_t> thickSkip1 = MathGlue::nonscript(MathGlue::thickGlue);
}
}