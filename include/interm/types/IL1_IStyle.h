/**
 * Created: Wed Aug 31 20:27:45 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "IL0_Item.h"

namespace formulae {
namespace interm {

class IStyle_t: public Item {
public:
  virtual ItemTag tag() const { return ItemTag::IStyle; }

  virtual gsl::owner<IStyle_t *> clone() const {
    return new IStyle_t(*this);
  }

  static ItemRef create(style_t style) {
    return ItemRef(new IStyle_t{style});
  }

  const style_t style;

protected:
  IStyle_t(style_t st) :  style(st) {}
};

}
}