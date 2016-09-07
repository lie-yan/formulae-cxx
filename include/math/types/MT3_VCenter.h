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

class VCenter_t: public Noad {
public:
  VCenter_t(const VCenter_t &) = default;
  VCenter_t(VCenter_t &&) = default;
  VCenter_t &operator=(const VCenter_t &) = default;
  VCenter_t &operator=(VCenter_t &&)      = default;
  virtual ~VCenter_t() = default;

  virtual NoadTag tag() const { return NoadTag::VCenter; }
  virtual kind_t kind() const { return kind_t::Ord; }
  virtual gsl::owner<VCenter_t *> clone() const {
    return new VCenter_t{*this};
  }

  template<typename MList = mlist_t>
  static NoadRef VCenter(MList &&mlist) {
    return NoadRef(new VCenter_t(std::forward<MList>(mlist)));
  }

protected:
  template<typename MList = mlist_t>
  VCenter_t(MList &&mlist) : mlist{std::forward<MList>(mlist)} {}

public:
  mlist_t mlist;
};
}
}