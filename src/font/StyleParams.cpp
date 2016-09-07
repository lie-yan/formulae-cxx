/**
 * Last modified: Tue Aug 30 19:40:55 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "StyleParams.h"
#include "Size.h"
#include "FontParams.h"

namespace formulae {
namespace font {

dist_t use1sy(const std::function<dist_t(fsize_t)> &f, style_t st) {
  return f(size(family_t::SY, st));
}

auto use2sy(std::function<dist_t(fsize_t)> f, std::function<dist_t(fsize_t)> g) {
  return [f, g](style_t st) {
    if (st == style_t::Display)
      return f(size(family_t::SY, style_t::Display));
    else
      return g(size(family_t::SY, st));
  };
}

dist_t use1ex(const std::function<dist_t(fsize_t)> &f, style_t st) {
  return f(size(family_t::EX, st));
}

dist_t xHeight(style_t st) {
  return math_x_height(size(family_t::SY, st));
}

dist_t MathUnit(style_t st) { return math_quad(size(family_t::SY, st)) / 18; }

dist_t atopNum(style_t st) { return use2sy(num1, num3)(st); }

dist_t fractNum(style_t st) { return use2sy(num1, num2)(st); }

dist_t Denom(style_t st) { return use2sy(denom1, denom2)(st); }

dist_t Sup(bool b, style_t st) {
  return b ? use1sy(sup3, st) : use2sy(sup1, sup2)(st);
}

dist_t SubAlone(style_t st) { return use1sy(sub1, st); }

dist_t SubWithSup(style_t st) { return use1sy(sub2, st); }

dist_t SupDrop(style_t st) { return use1sy(sup_drop, st); }

dist_t SubDrop(style_t st) { return use1sy(sub_drop, st); }

dist_t Delim(style_t st) { return use2sy(delim1, delim2)(st); }

dist_t AxisHeight(style_t st) { return use1sy(axis_height, st); }

dist_t RuleThickness(style_t st) { return use1ex(default_rule_thickness, st); }

dist_t BigOpSupDist(style_t st) { return use1ex(big_op_spacing1, st); }

dist_t BigOpSubDist(style_t st) { return use1ex(big_op_spacing2, st); }

dist_t BigOpSupPos(style_t st) { return use1ex(big_op_spacing3, st); }

dist_t BigOpSubPos(style_t st) { return use1ex(big_op_spacing4, st); }

dist_t BigOpPadding(style_t st) { return use1ex(big_op_spacing5, st); }
}
}