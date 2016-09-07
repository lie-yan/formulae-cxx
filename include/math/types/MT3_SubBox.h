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

class SubBox_t: public Noad {
public:
  SubBox_t(const SubBox_t &) = default;
  SubBox_t(SubBox_t &&) = default;
  SubBox_t &operator=(const SubBox_t &) = default;
  SubBox_t &operator=(SubBox_t &&)      = default;
  virtual ~SubBox_t() = default;

  virtual NoadTag tag() const { return NoadTag::SubBox; }
  virtual kind_t kind() const { return kind_t::Ord; }
  virtual gsl::owner<SubBox_t *> clone() const {
    return new SubBox_t{*this};
  }

  template<typename Box = node::box_t>
  static NoadRef create(Box &&box) {
    return NoadRef(new SubBox_t(std::forward<Box>(box)));
  }

protected:
  template<typename Box = node::box_t>
  SubBox_t(Box &&box) : box{std::forward<Box>(box)} {}

public:
  node::box_t box;
};
}
}