/**
 * Created: Wed Aug 31 20:56:24 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "MathTranslate.h"
#include "AxisCenter.h"

namespace formulae{
namespace translate {

namespace MathTranslate {

using namespace interm;
using namespace math;
using namespace node;

node::hlist_t NoadToHL(style_t st, bool cr, math::NoadRef &&noad) {
  using namespace node;
  using namespace math;

  switch (noad.tag()) {
    case NoadTag::MathChar: {
      auto& mathChar = noad.as<MathChar_t>();
      return makeChar(st, mathChar.family, mathChar.charCode);
    }
    case NoadTag::Radical: {
      auto& radical = noad.as<Radical_t>();
      return HL(
          makeRadical(st, radical.delim, cleanBox(st, true, std::move(radical.mlist))));
    }
    case NoadTag::Accent: {
      auto& accent = noad.as<Accent_t>();
      return HL(makeAccent(st, accent.family, accent.charCode,
                           cleanBox(st, true, std::move(accent.mlist))));
    }
    case NoadTag::VCenter: {
      return {axisCenter(st, cleanBox(st, cr, std::move(noad.as<VCenter_t>().mlist)))};
    }
    case NoadTag::Overline: {
      return HL(makeOver(st, cleanBox(st, true, std::move(noad.as<Overline_t>().mlist))));
    }
    case NoadTag::Underline: {
      return HL(makeUnder(st, cleanBox(st, true, std::move(noad.as<Underline_t>().mlist))));
    }
    case NoadTag::GenFraction: {
      return HL(doGenFraction(st, cr, std::move(noad.as<GenFraction_t>().genfraction)));
    }
    case NoadTag::LeftRight: {
      auto leftRight = noad.as<LeftRight_t>();
      return HL(doLeftRight(st, cr, leftRight.left, std::move(leftRight.mlist), leftRight.right));
    }
    case NoadTag::Script: {
      return doGenScripts(st, cr, false, false, std::move(noad.as<Script_t>().script));
    }
    case NoadTag::BigOp: {
      auto& bigOp = noad.as<BigOp_t>();
      return doBigOp(st, cr, bigOp.limits, std::move(bigOp.script));
    }
    case NoadTag::SubBox: {
      return HL(std::move(noad.as<SubBox_t>().box));
    }
    case NoadTag::MList: {
      return HL(cleanBox(st, cr, std::move(noad.as<MList_t>().mlist)));
    }
    case NoadTag::Kind: {
      return HL(cleanBox(st, cr, std::move(noad.as<Kind_t>().mlist)));
    }
    default:
      throw CannotHappen{};
      break;
  }
}

void ML2ILtrans(style_t st, bool cr, mlist_t &&ml, ilist_t &result) {
  using Elem = std::pair<mlist_t, int>;
  std::stack<Elem> stack;
  stack.push(std::make_pair(std::move(ml), 0));
  while (not stack.empty()) {
    Elem &cur = stack.top();
    if (cur.second >= cur.first.size()) {
      stack.pop();
      continue;
    } else {
      auto &term = cur.first[cur.second++];
      switch (term.tag()) {
        case NoadTag::MPen: {
          result.push_back(IPen_t::create(term.as<MPen_t>().penalty));
          break;
        }
        case NoadTag::MSpace: {
          result.push_back(ISpace_t::create(term.as<MSpace_t>().mathSpace));
          break;
        }
        case NoadTag::Style: {
          st = term.as<Style_t>().style;
          result.push_back(IStyle_t::create(st));
          break;
        }
        case NoadTag::Choice: {
          stack.push(std::make_pair(term.as<Choice_t>().choice(st), 0));
          break;
        }
        default:
          result.push_back(INoad_t::create(term.kind(),
                                        NoadToHList(st, cr, std::move(term))));
          break;
      }
    }
  }
}
}
}
}