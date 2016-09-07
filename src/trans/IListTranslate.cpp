/**
 * Created: Wed Aug 31 20:56:24 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "IListTranslate.h"

namespace formulae {
namespace translate {
namespace IListTranslate {

using namespace node;
using namespace math;
using namespace interm;
using namespace gsl;

// this function forces move semantic
int trans(style_t st, kind_t prevKind, span<interm::ItemRef> iList,
          hlist_t &result, bool insertPenalty) {

  if (iList.empty()) {
    return 0;
  } else {
    auto &first = *iList.begin();
    switch (first.tag()) {
      case ItemTag::IPen: {
        result.push_back(Penalty_t::create(first.as<IPen_t>().penalty));
        return trans(st, prevKind, iList.subspan(1), result, insertPenalty);
      }

      case ItemTag::ISpace: {
        auto sp = makeSpace(st, first.as<ISpace_t>().mathSpace);
        general::transfer(result, std::move(sp));
        return trans(st, prevKind, iList.subspan(1), result, insertPenalty);
      }

      case ItemTag::IStyle: {
        return trans(first.as<IStyle_t>().style,
                     prevKind,
                     iList.subspan(1),
                     result,
                     insertPenalty);
      }
      case ItemTag::INoad: {
        auto newKind = changeKind(prevKind,
                                  first.as<INoad_t>().kind,
                                  iList.subspan(1));

        auto spaceList = makeSpaceOpt(st, mathSpacing(prevKind, newKind));
        auto penaltyList = mathPenalty(insertPenalty, newKind, iList.subspan(1));

        general::transfer(result, std::move(spaceList));
        general::transfer(result, std::move(first.as<INoad_t>().hlist));
        general::transfer(result, std::move(penaltyList));
        return trans(st, newKind, iList.subspan(1), result, insertPenalty);
      }
    }
  }
}
} // namespace
}
}