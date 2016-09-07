/**
 * Last modified: Tue Aug 30 20:21:54 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"
#include "BoxTypes.h"
#include "Distance.h"

namespace formulae{
namespace node {

NodeRef rule(dist_t w, dist_t h);
glueSpec_t ssGlue();
box_t emptyBox();

template <typename NList = nlist_t>
box_t makebox(const boxkind_t &boxkind, dim_t dim, NList &&nl) {
  return box_t{boxkind, dim, std::forward<NList>(nl),
               glueParam_t::Tag::natural};
}

template <typename NList = nlist_t>
box_t hbox(dim_t dim, NList &&nl) {
  return makebox(boxkind_t::HBox, dim, std::forward<NList>(nl));
}

template <typename NList = nlist_t>
box_t vbox(dim_t dim, NList &&nl) {
  return makebox(boxkind_t::VBox, dim, std::forward<NList>(nl));
}

template <typename Node = NodeRef>
hlist_t extend(dist_t dist, Node &&node) {
  hlist_t ret{std::forward<Node>(node)};
  if (dist != zero())
    ret.push_back(Kern_t::create(dist));
  return ret;
}

template <typename Box = box_t>
NodeRef Box0(Box &&b) {
  return Box_t::create(std::forward<Box>(b), zero());
}

hlist_t HL(const box_t &box);
hlist_t HL(box_t &&box);

}
}
