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

class IPen_t: public Item {
public:
  virtual ItemTag tag() const { return ItemTag::IPen; }
  virtual gsl::owner<IPen_t *> clone() const {
    return new IPen_t(*this);
  }

  static ItemRef create(penalty_t penalty) {
    return ItemRef(new IPen_t(penalty));
  }

  const penalty_t penalty;

protected:
  IPen_t(penalty_t pen) : penalty(pen) {}
};

}
}