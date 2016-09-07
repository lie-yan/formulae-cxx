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

class MList_t: public Noad {
public:
  MList_t(const MList_t &) = default;
  MList_t(MList_t &&) = default;
  MList_t &operator=(const MList_t &) = default;
  MList_t &operator=(MList_t &&)      = default;
  virtual ~MList_t() = default;

  virtual NoadTag tag() const { return NoadTag::MList; }
  virtual kind_t kind() const { return kind_t::Ord; }
  virtual gsl::owner<MList_t *> clone() const {
    return new MList_t{*this};
  }

  template<typename MList = mlist_t>
  static NoadRef MList(MList &&mlist) {
    return NoadRef(new MList_t(std::forward<MList>(mlist)));
  }

protected:
  template<typename MList = mlist_t>
  MList_t(MList &&mlist) : mlist{std::forward<MList>(mlist)} {}

public:
  mlist_t mlist;
};
}
}