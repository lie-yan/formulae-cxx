#include "MakeScripts.h"
#include "BasicTypes.h"
#include "BoxTypes.h"
#include "ChangeStyle.h"
#include "StyleParams.h"

namespace formulae {
namespace node {

namespace MakeScripts {

dist_t almost_xHeight(style_t st) { return (font::xHeight(st) * 4) / 5; }

/**
 *
 * @param st
 * @param isChar
 * @param hnuc height of nucleus (my guess)
 * @return
 */
dist_t SupPos0(style_t st, bool isChar, dist_t hnuc) {
  using namespace font;
  return isChar ? zero() : hnuc - SupDrop(font::script(st));
}

/**
 *
 * @param st
 * @param isChar
 * @param dnuc depth of nucleus (my guess)
 * @return
 */
dist_t SubPos0(style_t st, bool isChar, dist_t dnuc) {
  using namespace font;
  return isChar ? zero() : dnuc + SubDrop(font::script(st));
}

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
              dist_t dsup) {
  std::vector<dist_t> list = {SupPos0(st, isChar, hnuc), font::Sup(cr, st),
                              dsup + font::xHeight(st) / 4};
  return *max_element(std::cbegin(list), std::cend(list));
}

dist_t SubAlonePos(style_t st, bool isChar, dist_t dnuc,
                   dist_t hsub) {
  std::vector<dist_t> list = {SubPos0(st, isChar, dnuc), font::SubAlone(st),
                              hsub - almost_xHeight(st)};
  return *max_element(std::cbegin(list), std::cend(list));
}

dist_t SubWithSupPos(style_t st, bool isChar, dist_t dnuc) {
  return std::max(SubPos0(st, isChar, dnuc), font::SubWithSup(st));
}

std::function<dist_t(style_t)> minSupDist = almost_xHeight;
dist_t minSupSubDist(style_t st) { return font::RuleThickness(st) * 4; }

std::tuple<dist_t, dist_t>
SupSubDistances(style_t st, bool cr, bool isChar, dist_t hnuc,
                dist_t dsup, dist_t dnuc, dist_t hsub) {
  auto supDist = SupPos(st, cr, isChar, hnuc, dsup) - dsup;
  auto subDist = SubWithSupPos(st, isChar, dnuc) - hsub;
  auto Dist = supDist + subDist;
  auto supDist1 = std::max(supDist, minSupDist(st));
  auto Dist1 = std::max(Dist, minSupSubDist(st));
  return std::make_tuple(supDist1, Dist1);
}

} // namespace MakeScripts}}
}
}