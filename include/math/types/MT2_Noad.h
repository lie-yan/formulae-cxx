/**
 * Created: Wed Aug 31 18:41:01 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "MT0.h"
#include "MT1_Space.h"

namespace formulae {
namespace math {

enum class NoadTag {
  MathChar,
  Radical,
  Accent,
  VCenter,
  Overline,
  Underline,
  GenFraction,
  LeftRight,
  Script,
  BigOp,
  SubBox,
  MList,
  Kind,
  MPen,
  MSpace,
  Style,
  Choice,
};

class Noad {
public:
  virtual ~Noad() = default;
  virtual NoadTag tag() const = 0;
  virtual gsl::owner<Noad *> clone() const = 0;
  virtual kind_t kind() const = 0;
};

class NoadRef {
public:
  /* ctor, dtor, operator= follow */
  NoadRef(gsl::owner<Noad *> noad) : _noad(noad) {}
  NoadRef(const NoadRef &rhs) { _noad.reset(rhs._noad->clone()); }
  NoadRef(NoadRef &&rhs) = default;
  ~NoadRef() = default;

  NoadRef &operator=(const NoadRef &rhs) {
    _noad.reset(rhs._noad->clone());
    return *this;
  }
  NoadRef &operator=(NoadRef &&rhs) = default;

  /*-------------------------------------------------------*/
  NoadTag tag() const { return _noad->tag(); }
  kind_t kind() const { return _noad->kind(); }

  template <typename T>
  T& as() const {
    return *dynamic_cast<T*>(_noad.get());
  }

protected:

private:
  std::unique_ptr<Noad> _noad;
};

using mlist_t = list_t<NoadRef>;

}
}