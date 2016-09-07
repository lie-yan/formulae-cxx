/**
 * Last modified: Tue Aug 30 20:39:09 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"
#include "BoxTypes.h"
#include "GlueCalculation.h"
namespace formulae{ namespace node {

/**
 *
 * @param dim desired with, plus (natural) height, plus (natural) depth
 * @param dw difference between desired and natural width
 * @param nl
 * @return
 */
template <typename HList= hlist_t>
box_t hlistGlue(dim_t dim, dist_t dw, HList &&nl) {
  auto gp = getGlueParam(dw, nl);
  return {boxkind_t::HBox, dim, std::forward<HList>(nl), gp};
}}}