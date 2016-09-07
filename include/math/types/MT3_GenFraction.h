/**
 * Created: Wed Aug 31 19:30:27 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once
#include "MT2_Noad.h"

namespace formulae {
namespace math {

struct genfraction_t {
  mlist_t top;
  mlist_t bot;
  optional <dist_t> thickness;
  delim_t left;
  delim_t right;
};

class GenFraction_t: public Noad {
public:
  GenFraction_t(const GenFraction_t &) = default;
  GenFraction_t(GenFraction_t &&) = default;
  GenFraction_t &operator=(const GenFraction_t &) = default;
  GenFraction_t &operator=(GenFraction_t &&)      = default;
  virtual ~GenFraction_t() = default;

  virtual NoadTag tag() const { return NoadTag::GenFraction; }
  virtual kind_t kind() const { return kind_t::Inner; }
  virtual gsl::owner<GenFraction_t *> clone() const {
    return new GenFraction_t{*this};
  }

  template<typename GenFract = genfraction_t>
  static NoadRef create(GenFract &&genfraction) {
    return NoadRef(new GenFraction_t(std::forward<GenFract>(genfraction)));
  }

protected:
  template<typename GenFract = genfraction_t>
  GenFraction_t(GenFract &&genfraction)
      : genfraction{std::forward<GenFract>(genfraction)} {}

public:
  genfraction_t genfraction;
};

}
}