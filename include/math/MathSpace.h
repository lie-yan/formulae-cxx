/**
 * Created: Tue Aug 30 21:26:10 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BoxTypes.h"
#include "MathTypes.h"

namespace formulae {
namespace math {

node::hlist_t makeSpace(style_t st, const mathSpace_t &ms);
node::hlist_t makeSpaceOpt(style_t st, const optional<mathSpace_t> &ms);

}
}