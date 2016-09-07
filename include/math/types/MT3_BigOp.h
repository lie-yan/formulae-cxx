/**
 * Created: Wed Aug 31 19:32:40 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once
#include "MT2_Noad.h"
#include "MT3_Script.h"

namespace formulae {
namespace math {

class BigOp_t: public Noad {
public:
  BigOp_t(const BigOp_t &) = default;
  BigOp_t(BigOp_t &&) = default;
  BigOp_t &operator=(const BigOp_t &) = default;
  BigOp_t &operator=(BigOp_t &&)      = default;
  virtual ~BigOp_t() = default;

  virtual NoadTag tag() const { return NoadTag::BigOp; }
  virtual kind_t kind() const { return kind_t::Op; }
  virtual gsl::owner<BigOp_t *> clone() const {
    return new BigOp_t{*this};
  }

  template<typename ScriptType = script_t>
  static NoadRef create(limits_t limits, ScriptType &&script) {
    return NoadRef(new BigOp_t(limits, std::forward<ScriptType>(script)));
  }

protected:
  template<typename ScriptType = script_t>
  BigOp_t(limits_t limits, ScriptType &&script)
      : limits{limits}, script{std::forward<ScriptType>(script)} {}

public:
  limits_t limits;
  script_t script;
};
}
}