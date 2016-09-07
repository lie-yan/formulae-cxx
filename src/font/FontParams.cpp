/**
 * Last modified: Tue Aug 30 19:18:14 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "FontParams.h"
#include "Distance.h"

namespace formulae {
namespace font {
dist_t math_x_height(fsize_t s) { return distRat(31 * s.value(), 72); }
dist_t math_quad(fsize_t s) {
  switch (s.value()) {
    case 10:
      return distInt(10);
    case 9:
      return distRat(333, 36);
    case 8:
      return distRat(306, 36);
    case 7:
      return distRat(295, 36);
    case 6:
      return distRat(276, 36);
    case 5:
      return distRat(265, 36);
    default:
      throw CannotHappen{};
  }
}
dist_t num1(fsize_t s) {
  switch (s.value()) {
    case 10:
      return distReal(real_t{6.765080});
    case 9:
      return distReal(real_t{5.820651});
    case 8:
      return distReal(real_t{5.570648});
    case 7:
      return distReal(real_t{5.126191});
    case 6:
      return distReal(real_t{4.876188});
    case 5:
      return distReal(real_t{4.626205});
    default:
      throw CannotHappen{};
  }
}
dist_t num2(fsize_t s) {
  switch (s.value()) {
    case 10:
      return distReal(real_t{3.937320});
    case 9:
      return distReal(real_t{3.687318});
    case 8:
      return distReal(real_t{3.270664});
    case 7:
      return distReal(real_t{2.687321});
    case 6:
      return distReal(real_t{2.353986});
    case 5:
      return distReal(real_t{1.937320});
    default:
      throw CannotHappen{};
  }
}
dist_t num3(fsize_t s) {
  switch (s.value()) {
    case 10:
      return distReal(real_t{4.437310});
    case 9:
      return distReal(real_t{4.048425});
    case 8:
      return distReal(real_t{3.659544});
    case 7:
      return distReal(real_t{3.298435});
    case 6:
      return distReal(real_t{2.909544});
    case 5:
      return distReal(real_t{2.520660});
    default:
      throw CannotHappen{};
  }
}
dist_t denom1(fsize_t s) {
  switch (s.value()) {
    case 10:
      return distReal(real_t{6.859510});
    case 9:
      return distReal(real_t{6.104007});
    case 8:
      return distReal(real_t{5.992872});
    case 7:
      return distReal(real_t{5.265050});
    case 6:
      return distReal(real_t{5.181732});
    case 5:
      return distReal(real_t{5.126205});
    default:
      throw CannotHappen{};
  }
}
dist_t denom2(fsize_t s) {
  switch (s.value()) {
    case 10:
      return distReal(real_t{3.448410});
    case 9:
      return distReal(real_t{3.054015});
    case 8:
      return distReal(real_t{3.137328});
    case 7:
      return distReal(real_t{2.409498});
    case 6:
      return distReal(real_t{2.576184});
    case 5:
      return distReal(real_t{2.659545});
    default:
      throw CannotHappen{};
  }
}

// auxilliary function
dist_t sup_sum(fsize_t s) {
  switch (s.value()) {
    case 10:
      return distRat(749, 100);
    case 9:
      return distRat(699, 100);
    case 8:
      return distRat(599, 100);
    case 7:
      return distRat(549, 100);
    case 6:
      return distRat(499, 100);
    case 5:
      return distRat(449, 100);
    default:
      throw CannotHappen{};
  }
}

dist_t sup_drop(fsize_t s) {
  switch (s.value()) {
    case 10:
      return distRat(139, 36);
    case 9:
      return distRat(114, 36);
    case 8:
      return distRat(114, 36);
    default:
      return distRat(89, 36);
  }
}

dist_t sup1(fsize_t s) { return sup2(s) + distRat(1, 2); }

dist_t sup2(fsize_t s) { return sup_sum(s) - sup_drop(s); }

dist_t sup3(fsize_t s) {
  switch (s.value()) {
    case 10:
      return distRat(104, 36);
    case 9:
      return distRat(93, 36);
    case 8:
      return distRat(82, 36);
    case 7:
      return distRat(72, 36);
    case 6:
      return distRat(62, 36);
    case 5:
      return distRat(53, 36);
    default:
      throw CannotHappen{};
  }
}

dist_t sub1(fsize_t s) {
  switch (s.value()) {
    case 10:
      return distRat(3, 2);
    default:
      return one();
  }
}

dist_t sub2(fsize_t s) {
  switch (s.value()) {
    case 10:
      return distRat(89, 36);
    case 9:
      return distRat(19, 12);
    default:
      return distInt(2);
  }
}

dist_t sub_drop(fsize_t s) { return distRat(1, 2); }

dist_t delim1(fsize_t s) {
  switch (s.value()) {
    case 10:
      return distRat(239, 10);
    case 9:
      return distRat(239, 10);
    case 8:
      return distRat(119, 10);
    case 7:
      return distRat(119, 10);
    case 6:
      return distRat(119, 10);
    case 5:
      return distRat(99, 10);
    default:
      throw CannotHappen{};
  }
}

dist_t delim2(fsize_t s) {
  switch (s.value()) {
    case 10:
      return distRat(101, 10);
    case 9:
      return distRat(91, 10);
    case 8:
      return distRat(91, 10);
    case 7:
      return distRat(81, 10);
    case 6:
      return distRat(81, 10);
    case 5:
      return distRat(71, 10);
    default:
      throw CannotHappen{};
  }
}

dist_t axis_height(fsize_t s) { return distRat(s.value(), 4); }

/**
 * The following are taken from the math extension fonts
 * which exist in sizes 10 and 9 only.
 */
dist_t default_rule_thickness(fsize_t s) {
  return distRat(10 + s.value(), 50);
}
dist_t big_op_spacing1(fsize_t s) { return distRat(s.value(), 9); }
dist_t big_op_spacing2(fsize_t s) { return distRat(s.value(), 6); }
dist_t big_op_spacing3(fsize_t s) { return distRat(s.value(), 5); }
dist_t big_op_spacing4(fsize_t s) {
  return distRat(4 + 5 * s.value(), 9);
}
dist_t big_op_spacing5(fsize_t s) { return one(); }
}
}
