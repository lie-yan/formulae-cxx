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
class LeftRight_t: public Noad {
public:
  LeftRight_t(const LeftRight_t &) = default;
  LeftRight_t(LeftRight_t &&) = default;
  LeftRight_t &operator=(const LeftRight_t &) = default;
  LeftRight_t &operator=(LeftRight_t &&)      = default;
  virtual ~LeftRight_t() = default;

  virtual NoadTag tag() const { return NoadTag::LeftRight; }
  virtual kind_t kind() const { return kind_t::Inner; }
  virtual gsl::owner<LeftRight_t *> clone() const {
    return new LeftRight_t{*this};
  }

  template<typename MList = mlist_t>
  static NoadRef create(delim_t left, MList &&mlist, delim_t right) {
    return NoadRef(new LeftRight_t(left, std::forward<MList>(mlist), right));
  }


protected:
  template<typename MList = mlist_t>
  LeftRight_t(delim_t left, MList &&mlist, delim_t right)
      : left{left}, mlist{std::forward<MList>(mlist)}, right{right} {}

public:
  delim_t left;
  mlist_t mlist;
  delim_t right;
};
}
}