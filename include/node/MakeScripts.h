#pragma once

#include "BasicTypes.h"
#include "BoxTypes.h"
#include "Const.h"
#include "BasicBox.h"
#include "MakeVBox.h"

namespace formulae{
namespace node {

namespace MakeScripts {

dist_t almost_xHeight(style_t st);

/**
 *
 * @param st
 * @param isChar
 * @param hnuc height of nucleus (my guess)
 * @return
 */
dist_t SupPos0(style_t st, bool isChar, dist_t hnuc);

/**
 *
 * @param st
 * @param isChar
 * @param dnuc depth of nucleus (my guess)
 * @return
 */
dist_t SubPos0(style_t st, bool isChar, dist_t dnuc);

/**
 *
 * @param st
 * @param cr      cramped
 * @param isChar
 * @param hnuc    height of nucleus
 * @param dsup    depth of supscript
 * @return
 */
dist_t SupPos(style_t st, bool cr, bool isChar, dist_t hnuc,
              dist_t dsup);

dist_t SubAlonePos(style_t st, bool isChar, dist_t dnuc,
                   dist_t hsub);

dist_t SubWithSupPos(style_t st, bool isChar, dist_t dnuc);

extern std::function<dist_t(style_t)> minSupDist;
dist_t minSupSubDist(style_t st);

std::tuple<dist_t, dist_t>
SupSubDistances(style_t st, bool cr, bool isChar, dist_t hnuc,
                dist_t dsup, dist_t dnuc, dist_t hsub);

template <typename Node = NodeRef> hlist_t extendScript(Node &&node) {
  return extend(GV::scriptSpace, std::forward<Node>(node));
}
} // namespace MakeScripts

template <typename Node = NodeRef, typename Box = box_t>
auto makeSup(style_t st, bool cr, bool isChar, dist_t itCorr,
             Node &&nucNode, Box &&supBox) {
  using namespace MakeScripts;
  auto shift = SupPos(st, cr, isChar, nucNode.height(), supBox.depth());
  auto scriptNode = Box_t::create(std::forward<Box>(supBox), -shift);

  auto ret = extend(itCorr, std::forward<Node>(nucNode));
  general::transfer(ret, extendScript(std::move(scriptNode)));
  return ret;
}

template <typename Node = NodeRef, typename Box = box_t>
auto makeSub(style_t st, bool isChar, Node &&nucNode, Box &&subBox) {
  using namespace MakeScripts;

  auto shift = SubAlonePos(st, isChar, nucNode.depth(), subBox.height());
  auto scriptNode = Box_t::create(std::forward<Box>(subBox), shift);

  auto ret = nlist_t{std::forward<Node>(nucNode)};
  general::transfer(ret, extendScript(std::move(scriptNode)));
  return ret;
}

template <typename Node = NodeRef, typename Box1 = box_t, typename Box2 = box_t>
auto makeSupSub(style_t st, bool cr, bool isChar, dist_t itCorr,
                Node &&nucNode, Box1 &&supBox, Box2 &&subBox) {
  using namespace MakeScripts;

  auto dnuc = nucNode.depth();
  auto hnuc = nucNode.height();
  auto dsup = supBox.depth();
  auto hsub = subBox.height();
  auto distances = SupSubDistances(st, cr, isChar, hnuc, dsup, dnuc, hsub);
  auto scriptNode =
      above(Box_t::create(supBox, itCorr), std::get<0>(distances),
            std::get<1>(distances), NodeRef(Box0(subBox)));

  auto ret = nlist_t{std::forward<Node>(nucNode)};
  general::transfer(ret, extendScript(std::move(scriptNode)));
  return ret;
}

template <typename Node = NodeRef, typename OptBox1 = optional<box_t>,
          typename OptBox2 = optional<box_t>>
auto makeScripts(style_t st, bool cr, bool isChar, dist_t itCorr,
                 Node &&node, OptBox1 &&supBox, OptBox2 &&subBox) {
  using namespace MakeScripts;
  if (not supBox) {
    if (not subBox) {
      return extend(itCorr, std::forward<Node>(node));
    } else {
      return makeSub(st, isChar, std::forward<Node>(node),
                     std::forward<OptBox2>(subBox).value());
    }
  } else {
    if (not subBox) {
      return makeSup(st, cr, isChar, itCorr, std::forward<Node>(node),
                     std::forward<OptBox1>(supBox).value());
    } else {
      return makeSupSub(st, cr, isChar, itCorr, std::forward<Node>(node),
                        std::forward<OptBox1>(supBox).value(),
                        std::forward<OptBox2>(subBox).value());
    }
  }
}}}