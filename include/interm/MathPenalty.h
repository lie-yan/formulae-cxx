/**
 * Last modified: Wed Aug 31 13:13:57 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "IListTypes.h"
#include "BoxTypes.h"
#include "MathTypes.h"

namespace formulae {
namespace interm {

node::hlist_t mathPenalty(bool b, math::kind_t actKind, gsl::span<ItemRef> rest);

}
}