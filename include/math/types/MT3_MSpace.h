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

class MSpace_t: public Noad {
public:
  virtual ~MSpace_t() = default;
  virtual NoadTag tag() const { return NoadTag::MSpace; }
  virtual kind_t kind() const { throw CannotHappen{}; }
  virtual gsl::owner<MSpace_t *> clone() const {
    return new MSpace_t{*this};
  }
  static NoadRef create(const mathSpace_t &mathSpace) {
    return NoadRef(new MSpace_t(mathSpace));
  }

protected:
  MSpace_t(const mathSpace_t &mathSpace) : mathSpace{mathSpace} {}

public:
  mathSpace_t mathSpace;
};
}
}