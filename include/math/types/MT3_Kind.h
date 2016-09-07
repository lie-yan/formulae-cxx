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
class Kind_t: public Noad {
public:
  Kind_t(const Kind_t &rhs) = default;
  Kind_t(Kind_t &&rhs) = default;
  Kind_t &operator=(const Kind_t &rhs) = default;
  Kind_t &operator=(Kind_t &&rhs)      = default;
  virtual ~Kind_t() = default;

  virtual NoadTag tag() const { return NoadTag::Kind; }
  virtual kind_t kind() const { return _kind; }
  virtual gsl::owner<Kind_t *> clone() const {
    return new Kind_t{*this};
  }
  template<typename MList = mlist_t>
  static NoadRef create(kind_t kind, MList &&mlist) {
    return NoadRef(new Kind_t(kind, std::forward<MList>(mlist)));
  }
protected:
  template<typename MList = mlist_t>
  Kind_t(kind_t kind, MList &&mlist)
      : _kind{kind}, mlist{std::forward<MList>(mlist)} {}

private:
  kind_t _kind;
public:
  mlist_t mlist;
};
}
}