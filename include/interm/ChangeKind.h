/**
 *
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "IListTypes.h"

namespace formulae {
namespace interm {

math::kind_t changeKind(math::kind_t prevKind, math::kind_t kind, gsl::span<ItemRef> list);
}
}