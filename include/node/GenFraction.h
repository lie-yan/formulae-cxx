#pragma once

#include "BoxTypes.h"
#include "BoxPack.h"
#include "StyleParams.h"
#include "MakeAtop.h"
#include "MakeFract.h"
#include "Delimiter.h"
namespace formulae{ namespace node {

template <typename Box1=box_t, typename Box2=box_t>
box_t makeGenFraction(style_t  st, const optional<dist_t> & thickness,
                      delim_t  left, delim_t  right,
                      Box1 && numBox, Box2 && denBox) {
  using std::forward;
  using std::move;
  auto width     = std::max(numBox.width(), denBox.width());
  auto numBox1   = rebox(width, forward<Box1>(numBox));
  auto denBox1   = rebox(width, forward<Box2>(denBox));
  auto th        = general::optVal(font::RuleThickness(st))(thickness);
  auto middle    = (th == zero()) ? makeAtop(st, move(numBox1), move(denBox1))
                                : makeFract(st, th, width, move(numBox1), move(denBox1));
  auto leftNode  = makeDelimiter(st, left);
  auto rightNode = makeDelimiter(st, right);
  return boxList(nlist_t{leftNode, move(middle), rightNode});
};}}