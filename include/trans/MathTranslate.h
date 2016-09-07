/**
 * Created: Wed Aug 31 20:56:24 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "Accent.h"
#include "Boundaries.h"
#include "BoxTypes.h"
#include "ChangeStyle.h"
#include "GenFraction.h"
#include "IListTranslate.h"
#include "MakeChar.h"
#include "MakeLimOp.h"
#include "MakeLine.h"
#include "MakeScripts.h"
#include "MathSpace.h"
#include "MathTypes.h"
#include "Radical.h"
#include <stack>

namespace formulae {
namespace translate {
template<typename MList = math::mlist_t>
node::box_t cleanBox(style_t st, bool cr, MList &&ml);

template<typename GenFract = math::genfraction_t>
node::box_t doGenFraction(style_t st, bool cr, GenFract &&genfrac);

template<typename MList = math::mlist_t>
node::box_t doLeftRight(style_t st, bool cr, delim_t left, MList &&ml,
                        delim_t right);

template<typename MList = math::mlist_t>
std::tuple<node::NodeRef, dist_t, bool> doNucleus(style_t st, bool cr, bool isOp,
                                                 MList &&ml);

template<typename Script = math::script_t>
node::hlist_t doGenScripts(style_t st, bool cr, bool limits, bool isOp,
                           Script &&script);

template<typename Script = math::script_t>
node::hlist_t doBigOp(style_t st, bool cr, const math::limits_t &lim,
                      Script &&scrp);

template<typename Noad = math::NoadRef>
node::hlist_t NoadToHList(style_t st, bool cr, Noad &&noad);

template<typename MList = math::mlist_t>
interm::ilist_t MListToIList(style_t st, bool cr, MList &&ml);

template<typename MList = math::mlist_t>
node::hlist_t MListToHList(style_t st, bool cr, bool pen, MList &&ml);

/**
 * definitions below
 */

template<typename MList>
node::box_t cleanBox(style_t st, bool cr, MList &&ml) {
  return boxList(
      MListToHList(st, cr, false /* no penalties */, std::forward<MList>(ml)));
}

template<typename GenFract>
node::box_t doGenFraction(style_t st, bool cr, GenFract &&genfrac) {
  auto st1 = font::fract(st);
  auto numbox = cleanBox(st1, cr, std::forward<GenFract>(genfrac).top);
  auto denbox = cleanBox(st1, true, std::forward<GenFract>(genfrac).bot);
  return makeGenFraction(st, genfrac.thickness, genfrac.left, genfrac.right,
                         std::move(numbox), std::move(denbox));
}


/**
 * translate `ml` to `hlist_t` with the left/right delimiters attached
 * @param st
 * @param cr
 * @param left
 * @param ml
 * @param right
 * @return
 */
template<typename MList>
node::box_t doLeftRight(style_t st, bool cr, delim_t left, MList &&ml,
                        delim_t right) {
  auto il = MListToIList(st, cr, std::forward<MList>(ml));
  auto il1 = attachBoundaries(st, left, right, std::move(il)); // attach the delimiters to the `il`
  return boxList(IListToHList(st, false, std::move(il1)));
}

template<typename MList>
std::tuple<node::NodeRef, dist_t, bool> doNucleus(style_t st, bool cr, bool isOp,
                                                 MList &&ml) {

  if (isOp and ml.size() == 1 and ml.begin()->tag() == math::NoadTag::MathChar) {
    auto &mathChar = ml.begin()->template as<math::MathChar_t>();
    return node::makeNucChar(st, isOp, mathChar.family, mathChar.charCode);
  } else {
    return std::make_tuple(node::Box0(cleanBox(st, cr, std::forward<MList>(ml))), zero(), false);
  }
}

template<typename Script>
node::hlist_t doGenScripts(style_t st, bool cr, bool limits, bool isOp,
                           Script &&script) {
  using std::move;
  using std::forward;
  using namespace math;
  using namespace node;
  using namespace general;

  node::NodeRef nucNode;
  dist_t itCorr;
  bool isChar;
  std::tie(nucNode, itCorr, isChar) =
      doNucleus(st, cr, isOp, forward<Script>(script).nucleus);
  auto st1 = font::script(st);
  auto supOptBox = optMap<mlist_t, box_t>([st1, cr](auto &&ml) {
    return cleanBox(st1, cr, forward<decltype(ml)>(ml));
  })(script.supOpt);
  auto subOptBox = optMap<mlist_t, box_t>([st1](auto &&ml) {
    return cleanBox(st1, true, forward<decltype(ml)>(ml));
  })(script.subOpt);

  if (limits)
    return HL(makeLimOp(st, itCorr, std::move(nucNode), std::move(supOptBox),
                        std::move(subOptBox)));
  else
    return makeScripts(st, cr, isChar, itCorr, std::move(nucNode),
                       std::move(supOptBox), std::move(subOptBox));
}

template<typename Script>
node::hlist_t doBigOp(style_t st, bool cr, const math::limits_t &lim,
                      Script &&scrp) {
  auto limits = (st == style_t::Display and lim == math::limits_t::Default) or
      (lim == math::limits_t::Yes);
  return doGenScripts(st, cr, limits, true, std::forward<Script>(scrp));
}

namespace MathTranslate {

using namespace interm;
using namespace math;
using namespace node;

node::hlist_t NoadToHL(style_t st, bool cr, math::NoadRef && noad); // forces move semantic
void ML2ILtrans(style_t st, bool cr, math::mlist_t && ml, ilist_t & result); // forces move semantic
}

template<typename Noad>
node::hlist_t NoadToHList(style_t st, bool cr, Noad &&noad) {
  auto localCopy = std::forward<Noad>(noad);
  return MathTranslate::NoadToHL(st, cr, std::move(localCopy));
}

template<typename MList>
interm::ilist_t MListToIList(style_t st, bool cr, MList &&ml) {
  auto localCopy = std::forward<MList>(ml);
  interm::ilist_t result;
  MathTranslate::ML2ILtrans(st, cr, std::move(localCopy), result);
  return result;
}

template<typename MList>
node::hlist_t MListToHList(style_t st, bool cr, bool pen, MList &&ml) {
  auto il = MListToIList(st, cr, std::forward<MList>(ml));
  auto hl = IListToHList(st, pen, std::move(il));
  return hl;
}
}
}