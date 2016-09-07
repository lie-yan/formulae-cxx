/**
 * Last modified: Wed Aug 31 13:13:57 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "MathPenalty.h"
#include "Const.h"



namespace formulae {
namespace interm {

static bool allowPenalty(gsl::span<ItemRef> list) {
  if (list.empty())
    return false;
  else {
    const auto& first = *list.begin();
    switch (first.tag()) {
      case ItemTag::IPen:
        return false;
      case ItemTag::INoad:
        return first.as<INoad_t>().kind != math::kind_t::Rel;
      default:
        return true;
    }
  }
}

static node::hlist_t makeList(penalty_t pen) {
  return pen == GV::infPenalty ? node::hlist_t{}
                               : node::hlist_t{node::Penalty_t::create(pen)};
}

static node::hlist_t penaltyList(math::kind_t kind) {
  using math::kind_t;
  switch (kind) {
    case kind_t::Bin:
      return makeList(GV::binopPenalty);
    case kind_t ::Rel:
      return makeList(GV::relPenalty);
    default:
      return {};
  }
}


node::hlist_t mathPenalty(bool b, math::kind_t actKind, gsl::span<ItemRef> rest) {
  if (! b)
    return {};
  else {
    return allowPenalty(rest) ? penaltyList(actKind)
                              : node::hlist_t{};
  }
}
}
}