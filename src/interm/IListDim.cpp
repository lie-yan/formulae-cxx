/**
 *
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "IListDim.h"
#include "BoxTypes.h"
#include "IListTypes.h"
#include "NodeListDim.h"
#include <functional>

namespace formulae {
namespace interm {

static dist_t ilistDim(std::function<dist_t(node::hlist_t)> dimFunc, const ilist_t & list) {
  auto length = zero();
  for (const auto &item : list) {
    if (item.tag() == ItemTag::INoad)
      length = std::max(length,
                        dimFunc(item.as<INoad_t>().hlist));
  }
  return length;
}

dist_t ilistHeight(const ilist_t &list) {
  return ilistDim(node::hlistHeight, list);
}

dist_t ilistDepth(const ilist_t &list) {
  return ilistDim(node::hlistDepth, list);
}
} // namespace
}