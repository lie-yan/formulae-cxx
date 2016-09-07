/**
 * Created: Wed Aug 31 17:21:50 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "MT0.h"
#include "BasicTypes.h"
#include "BoxTypes.h"

namespace formulae{
namespace math{

enum class SpaceTag {
  SKern,
  SGlue,
};

struct Space_t {
  virtual SpaceTag tag() const = 0;
  virtual gsl::owner<Space_t *> clone() const = 0;
};

struct SKern_t : public Space_t {
  SKern_t(dist_t d) : size(d) { }
  virtual SpaceTag tag() const { return SpaceTag::SKern; }
  virtual gsl::owner<Space_t *> clone() const {
    return new SKern_t(*this);
  }

  dist_t size;
};

struct SGlue_t : public Space_t {
  SGlue_t(node::glueSpec_t spec) : spec(spec) {}
  virtual SpaceTag tag() const { return SpaceTag::SGlue; }
  virtual gsl::owner<Space_t *> clone() const {
    return new SGlue_t(*this);
  }

  node::glueSpec_t spec;
};

class SpaceRef {
public:
  /* ctor, dtor, operator= follow */
  SpaceRef(const Space_t &sp) : _space(sp.clone()) {}
  SpaceRef(const SpaceRef &sp) : SpaceRef(*sp._space) {}
  SpaceRef &operator=(const SpaceRef &sp) {
    _space.reset(sp._space->clone());
    return *this;
  }
  SpaceRef() = default;
  SpaceRef(SpaceRef &&) = default;
  SpaceRef &operator=(SpaceRef &&) = default;

  /* tag */
  SpaceTag tag() const { return _space->tag(); }

  template <typename T>
  T& as() const {
    return *dynamic_cast<T*>(_space.get());
  }

private:
  std::unique_ptr<Space_t> _space;
};

struct mathSpace_t {
  bool isMu;
  bool always;
  SpaceRef entry;
};
}
}