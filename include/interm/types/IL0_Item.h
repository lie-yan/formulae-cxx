/**
 * Created: Wed Aug 31 20:27:45 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include <gsl.h>

namespace formulae {
namespace interm {

enum class ItemTag : uint8_t { INoad, IPen, ISpace, IStyle };

struct Item {
  virtual ItemTag tag() const = 0;
  virtual gsl::owner<Item *> clone() const = 0;
};

class ItemRef {
public:
  ItemRef(gsl::owner<Item *> itemPtr) : _itemPtr(itemPtr) {}
  ItemRef(const ItemRef &rhs) { _itemPtr.reset(rhs._itemPtr->clone()); }
  ItemRef &operator=(const ItemRef &rhs) {
    _itemPtr.reset(rhs._itemPtr->clone());
    return *this;
  }
  ItemRef(ItemRef &&rhs) = default;
  ItemRef &operator=(ItemRef &&rhs) = default;
  virtual ~ItemRef() = default;

  /* -------------------------------------------------------- */
  ItemTag tag() const { return _itemPtr->tag(); }

  template<typename T>
  T& as() const { return *dynamic_cast<T*>(_itemPtr.get()); }

private:
  std::unique_ptr<Item> _itemPtr;
};

using ilist_t = list_t<ItemRef>;

}
}
