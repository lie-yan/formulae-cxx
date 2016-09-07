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

class MPen_t: public Noad {
public:
  virtual ~MPen_t() = default;
  virtual NoadTag tag() const { return NoadTag::MPen; }
  virtual kind_t kind() const { throw CannotHappen{}; }
  virtual gsl::owner<MPen_t *> clone() const {
    return new MPen_t{*this};
  }
  static NoadRef create(penalty_t penalty) {
    return NoadRef(new MPen_t(penalty));
  }
protected:
  MPen_t(penalty_t penalty) : penalty{penalty} {}

public:
  const penalty_t penalty;
};
}
}