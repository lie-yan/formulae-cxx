/**
 * Created: Wed Aug 31 19:27:13 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once
#include "MT2_Noad.h"

namespace formulae {
namespace math {

class Underline_t: public Noad {
public:
  Underline_t(const Underline_t &) = default;
  Underline_t(Underline_t &&) = default;
  Underline_t &operator=(const Underline_t &) = default;
  Underline_t &operator=(Underline_t &&)      = default;
  virtual ~Underline_t() = default;

  virtual NoadTag tag() const { return NoadTag::Underline; }
  virtual kind_t kind() const { return kind_t::Ord; }
  virtual gsl::owner<Underline_t *> clone() const {
    return new Underline_t{*this};
  }

  template<typename MList = mlist_t>
  static NoadRef create(MList &&mlist) {
    return NoadRef(new Underline_t(std::forward<MList>(mlist)));
  }

protected:
  template<typename MList = mlist_t>
  Underline_t(MList &&mlist) : mlist{std::forward<MList>(mlist)} {}

public:
  mlist_t mlist;
};
}
}