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

class Choice_t: public Noad {
public:
  virtual ~Choice_t() = default;
  virtual NoadTag tag() const { return NoadTag::Choice; }
  virtual kind_t kind() const { throw CannotHappen{}; }
  virtual gsl::owner<Choice_t *> clone() const {
    return new Choice_t{*this};
  }

  static NoadRef create(std::function<mlist_t(style_t)> choice) {
    return NoadRef(new Choice_t(choice));
  }
protected:
  Choice_t(std::function<mlist_t(style_t)> choice) : choice{choice} {}

public:
  std::function<mlist_t(style_t)> choice;
};
}
}