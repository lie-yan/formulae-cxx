/**
 * Created: Wed Aug 31 20:27:45 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "IL0_Item.h"

namespace formulae{
namespace interm{

class ISpace_t : public Item {
public:
  virtual ItemTag tag() const { return ItemTag::ISpace; }

  virtual gsl::owner<ISpace_t *> clone() const {
    return new ISpace_t(*this);
  }

  template<typename MathSpace = math::mathSpace_t>
  static ItemRef create(MathSpace && ms) {
    return ItemRef(new ISpace_t{std::forward<MathSpace>(ms)});
  }

  const math::mathSpace_t mathSpace;

protected:
  ISpace_t(const math::mathSpace_t &sp) :  mathSpace(sp) {}
};

}
}