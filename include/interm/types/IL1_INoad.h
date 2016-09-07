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

class INoad_t: public Item {
public:
  virtual ItemTag tag() const { return ItemTag::INoad; }

   virtual gsl::owner<INoad_t *> clone() const {
    return new INoad_t(*this);
  }

  template<typename List = node::hlist_t>
  static ItemRef create(math::kind_t kind, List && list) {
    return ItemRef(new INoad_t{kind, std::forward<List>(list)});
  }

  const math::kind_t kind;
  node::hlist_t hlist;

protected:
  template<typename List = node::hlist_t>
  INoad_t(math::kind_t kind, List &&list)
      :  kind(kind), hlist(std::forward<List>(list)) {}

};
}
}