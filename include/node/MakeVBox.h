#pragma once

#include "BasicBox.h"
#include "BasicTypes.h"
#include "BoxTypes.h"
#include "General.h"
#include "NodeDim.h"
#include "NodeListDim.h"
#include <gsl.h>

namespace formulae{ namespace node {

/**
 *
 * @param width
 * @param node center node -> reference point, (must be Box0 or Rule !!!)
 * @param upList above center, enumerated from bottom to top
 * @param dnList below center, enumerated from top to bottom
 * @return
 */
template<typename VList1=vlist_t, typename VList2=vlist_t, typename Node=NodeRef>
box_t makeVBox(dist_t  width, Node && node,
               VList1 && upList, VList2 && dnList) {

  using general::revAppend;
  using general::transfer;
  
  auto h = vlistVsize(upList) + node.height();
  auto d = vlistVsize(dnList) + node.depth();
  std::remove_reference_t<VList1> emptyList;
  auto nodeList = revAppend(std::forward<VList1>(upList), emptyList);
  nodeList.push_back(std::forward<Node>(node));
  transfer(nodeList, std::forward<VList2>(dnList));

  return vbox(dim_t{width, h, d}, std::move(nodeList));
}
/**
 *
 * @param width
 * @param center center node -> reference point,
 * @param upList above center, enumerated from bottom to top
 * @return
 */
template <typename Box = box_t, typename VList = vlist_t>
box_t upVBox(dist_t  width, Box && center, VList&& upList) {
  std::remove_reference_t<VList> emptyList;
  return makeVBox(width, NodeRef{Box0(std::forward<Box>(center))},
                  std::forward<VList>(upList), emptyList);
}

/**
 *
 * @param width
 * @param center center node -> reference point
 * @param dnList below center, enumerated from top to bottom
 * @return
 */
template <typename Box = box_t, typename VList = vlist_t>
box_t dnVBox(dist_t  width, Box && center, VList && dnList) {
  std::remove_reference_t<VList> emptyList;
  return makeVBox(width, Box0(std::forward<Box>(center)), emptyList, std::forward<VList>(dnList));
}

/**
 *
 * @param n1
 * @param dist1 distance from bottom of n1 to baseline
 * @param dist  vertical distance between n1 and n2
 * @param n2
 * @return
 */
template <typename Node = NodeRef, typename DownNode=NodeRef>
NodeRef above(Node && n1, dist_t  dist1, dist_t  dist, DownNode && n2) {
  auto w = std::max(n1.vwidth(), n2.vwidth());
  auto h = n1.vsize() + dist1;
  auto d = n2.vsize() + dist - dist1;
  using E = std::remove_reference_t<Node>;
  list_t<E> nodeList;
  nodeList.push_back(std::forward<Node>(n1));
  nodeList.push_back(Kern_t::create(dist));
  nodeList.push_back(std::forward<DownNode>(n2));
  return Box0(vbox(dim_t{w, h, d}, std::move(nodeList)));
};



}
}