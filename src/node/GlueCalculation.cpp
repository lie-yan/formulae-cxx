/**
 * Last modified: Tue Aug 30 20:26:14 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "GlueCalculation.h"

namespace formulae{ namespace node {

list_t<glueSpec_t::subSpec_t>
extractGlue(std::function<glueSpec_t::subSpec_t(glueSpec_t)> access,
            const list_t<NodeRef> &list) {
  list_t<glueSpec_t::subSpec_t> ret;

  for (const auto &node : list) {
    if (node.tag() == NodeTag::Glue) {
      ret.push_back(access(node.as<Glue_t>().glueSpec()));
    }
  }
  return ret;
}

dist_t addGlue(const infOrder_t &ord,
               const list_t<glueSpec_t::subSpec_t> &list) {
  dist_t sum = zero();
  for (const auto &spec : list) {
    if (ord == spec.infOrder)
      sum += spec.dist;
  }
  return sum;
}

glueSpec_t::subSpec_t totalGlue(const list_t<glueSpec_t::subSpec_t> &gl) {
  static const std::vector<infOrder_t> infOrds{
      infOrder_t::filll, infOrder_t::fill, infOrder_t::fil, infOrder_t::normal};

  for (const auto &ord : infOrds) {
    auto sum = addGlue(ord, gl);
    if (sum != zero())
      return glueSpec_t::subSpec_t{sum, ord};
  }
  throw Rigid{};
}

glueParam_t getGlueParam(dist_t dw, const list_t<NodeRef> &nl) {
  try {
    if (dw > zero()) {
      auto access = [](const glueSpec_t & gs) { return gs.stretch; };
      auto s = totalGlue(extractGlue(access, nl));
      return glueParam_t::stretching(real_t{1.0 * dw.value() / s.dist.value()},
                                     s.infOrder);
    } else if (dw < zero()) {
      auto access = [](const glueSpec_t & gs) { return gs.shrink; };
      auto s = totalGlue(extractGlue(access, nl));
      return glueParam_t::stretching(real_t{-1.0 * dw.value() / s.dist.value()},
                                     s.infOrder);
    } else {
      return glueParam_t::natural();
    }
  } catch (Rigid &ex) {
    return glueParam_t::natural();
  }
}}}