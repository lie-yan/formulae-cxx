/**
 * Created: Wed Aug 31 19:32:40 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once
#include "MT2_Noad.h"

namespace formulae {
namespace math {

class Style_t: public Noad {
public:
  virtual ~Style_t() = default;
  virtual NoadTag tag() const { return NoadTag::Style; }
  virtual kind_t kind() const { throw CannotHappen{}; }
  virtual gsl::owner<Style_t *> clone() const {
    return new Style_t{*this};
  }
  static NoadRef create(style_t style) { return NoadRef(new Style_t(style)); }

protected:
  Style_t(style_t style) : style{style} {}

public:
  style_t style;
};
}
}