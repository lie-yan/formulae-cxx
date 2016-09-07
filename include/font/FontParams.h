/**
 * Last modified: Tue Aug 30 19:18:14 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"
#include "Size.h"
namespace formulae {
namespace font {

dist_t math_x_height(fsize_t s); // height of `x`
dist_t math_quad(fsize_t s);     // width of `M`

dist_t num1(fsize_t s); // numerator shift-up in display style
dist_t num2(fsize_t s); // numerator shift-up in non-display, non-atop
dist_t num3(fsize_t s); // numerator shift-up in non-display atop

dist_t denom1(fsize_t s); // denominator shift-down in display style
dist_t denom2(fsize_t s); // denominator shift-down in non-display styles

dist_t sup1(fsize_t s); // superscript shift-up in uncramped display style

dist_t sup2(fsize_t s); // superscript shift-up in uncramped non-display styles
dist_t sup3(fsize_t s); // superscript shift-up in cramped styles

dist_t sub1(fsize_t s); // subscript shift-down if superscript is absent
dist_t sub2(fsize_t s); // subscript shift-down if superscript is present

dist_t sup_drop(fsize_t s); // superscript baseline below top of large box
dist_t sub_drop(fsize_t s); // subscript baseline below bottom of large box

dist_t delim1(fsize_t s); // size of delimiters in display styles
dist_t delim2(fsize_t s); // size of delimiters in non-displays

dist_t axis_height(fsize_t s); // height of fraction lines above the baseline
dist_t default_rule_thickness(fsize_t s); // thickness of fraction strokes

dist_t big_op_spacing1(fsize_t s); // minimum clearance above
dist_t big_op_spacing2(fsize_t s); // minimum clearance below
dist_t big_op_spacing3(fsize_t s); // minimum baselineskip above
dist_t big_op_spacing4(fsize_t s); // minimum baselineskip below
dist_t big_op_spacing5(fsize_t s); // padding above and below
}
}