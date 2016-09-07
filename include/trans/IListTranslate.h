/**
 * Created: Wed Aug 31 15:36:05 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"
#include "BoxTypes.h"
#include "IListTypes.h"
#include "MathSpace.h"
#include "Spacing.h"
#include "ChangeKind.h"
#include "MathPenalty.h"

namespace formulae {
namespace translate {

namespace IListTranslate {

// this function forces move semantic
int trans(style_t st, math::kind_t prevKind, gsl::span<interm::ItemRef> iList,
          node::hlist_t & result, bool insertPenalty);
}

template<typename IList = interm::ilist_t>
node::hlist_t IListToHList(style_t st, bool insertPenalty, IList &&iList) {
  interm::ilist_t iListCopy = std::forward<IList>(iList);
  gsl::span<interm::ItemRef> iListSpan = iListCopy;
  node::hlist_t ret = {};
  IListTranslate::trans(st,
                        math::kind_t::None,
                        iListSpan,
                        ret,
                        insertPenalty);
  return ret;
}
}
}