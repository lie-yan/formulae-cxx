/**
 * Created: Wed Aug 31 19:22:12 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */


#pragma once
#include "MT2_Noad.h"

namespace formulae {
namespace math {

class Radical_t: public Noad {
public:
  Radical_t(const Radical_t &) = default;
  Radical_t(Radical_t &&) = default;
  Radical_t &operator=(const Radical_t &) = default;
  Radical_t &operator=(Radical_t &&)      = default;
  virtual ~Radical_t() = default;

  virtual NoadTag tag() const { return NoadTag::Radical; }
  virtual kind_t kind() const { return kind_t::Ord; }
  virtual gsl::owner<Radical_t *> clone() const {
    return new Radical_t{*this};
  }

  template<typename MList = mlist_t>
  static NoadRef create(delim_t delim, MList &&mlist) {
    return NoadRef(new Radical_t(delim, std::forward<MList>(mlist)));
  }


protected:
  template<typename MList = mlist_t>
  Radical_t(delim_t delim, MList &&mlist)
      : delim{delim}, mlist{std::forward<MList>(mlist)} {}

public:
  delim_t delim;
  mlist_t mlist;
};
}
}