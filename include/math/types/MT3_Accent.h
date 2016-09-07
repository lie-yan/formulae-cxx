/**
 * Created: Wed Aug 31 19:23:32 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once
#include "MT2_Noad.h"

namespace formulae {
namespace math {

class Accent_t: public Noad {
public:
  Accent_t(const Accent_t &) = default;
  Accent_t(Accent_t &&) = default;
  Accent_t &operator=(const Accent_t &) = default;
  Accent_t &operator=(Accent_t &&)      = default;
  virtual ~Accent_t() = default;

  /*----------------------------------------------------------*/
  virtual NoadTag tag() const { return NoadTag::Accent; }
  virtual kind_t kind() const { return kind_t::Ord; }
  virtual gsl::owner<Accent_t *> clone() const {
    return new Accent_t{*this};
  }

  template<typename MList = mlist_t>
  static NoadRef Accent(family_t family, charCode_t charCode, MList &&mlist) {
    return NoadRef(new Accent_t(family, charCode, std::forward<MList>(mlist)));
  }


protected:
  template<typename MList = mlist_t>
  Accent_t(family_t family, charCode_t charCode, MList &&mlist)
      : family{family}, charCode{charCode},
        mlist{std::forward<MList>(mlist)} {}

public:
  family_t family;
  charCode_t charCode;
  mlist_t mlist;
};
}
}