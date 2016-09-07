/**
 * Last modified: Wed Aug 31 13:47:46 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"
#include "BoxTypes.h"
#include "IListTypes.h"
#include "IListDim.h"

namespace formulae {
namespace interm {

std::tuple<node::NodeRef, node::NodeRef>
makeBoundaries(style_t st, dist_t height, dist_t depth, delim_t left, delim_t right);

template<typename List = ilist_t>
ilist_t attachBoundaries(style_t st, delim_t left, delim_t right,
                         List &&il) {
  using math::kind_t;
  auto height = ilistHeight(il);
  auto depth = ilistDepth(il);
  node::NodeRef leftNode, rightNode;
  std::tie(leftNode, rightNode) = makeBoundaries(st, height, depth, left, right);
  auto makeIList = [](kind_t kind, auto &&node) {
    return INoad_t::create(kind, node::hlist_t{std::move(node)});
  };

  auto ret = ilist_t{};
  ret.push_back(makeIList(kind_t::Open, std::move(leftNode)));
  general::transfer(ret, std::forward<List>(il));
  ret.push_back(makeIList(kind_t::Close, std::move(rightNode)));
  return ret;
}
}
}