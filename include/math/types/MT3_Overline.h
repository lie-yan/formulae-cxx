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

class Overline_t: public Noad {
public:
  Overline_t(const Overline_t &) = default;
  Overline_t(Overline_t &&) = default;
  Overline_t &operator=(const Overline_t &) = default;
  Overline_t &operator=(Overline_t &&)      = default;
  virtual ~Overline_t() = default;

  virtual NoadTag tag() const { return NoadTag::Overline; }
  virtual kind_t kind() const { return kind_t::Ord; }
  virtual gsl::owner<Overline_t *> clone() const {
    return new Overline_t{*this};
  }

  template<typename MList = mlist_t>
  static NoadRef create(MList &&mlist) {
    return NoadRef(new Overline_t(std::forward<MList>(mlist)));
  }

protected:
  template<typename MList = mlist_t>
  Overline_t(MList &&mlist) : mlist{std::forward<MList>(mlist)} {}

public:
  mlist_t mlist;
};
}
}