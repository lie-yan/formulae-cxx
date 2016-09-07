/**
 * Created: Wed Aug 31 19:14:14 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "MT2_Noad.h"

namespace formulae{
namespace math {
  
class MathChar_t : public Noad {
public:
  virtual ~MathChar_t() = default;
  virtual NoadTag tag() const { return NoadTag::MathChar; }
  virtual kind_t kind() const { return _kind; }
  virtual gsl::owner<MathChar_t *> clone() const {
    return new MathChar_t{*this};
  }

  static NoadRef create(kind_t kind, family_t family, charCode_t charCode) {
    return NoadRef(new MathChar_t(kind, family, charCode));
  }

protected:
  MathChar_t(kind_t kind, family_t family, charCode_t charCode)
  : _kind{kind}, family{family}, charCode{charCode} {}

private:
  kind_t _kind;
public:
  family_t family;
  charCode_t charCode;
};
}
}