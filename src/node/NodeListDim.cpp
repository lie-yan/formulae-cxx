/**
 * Last modified: Tue Aug 30 19:51:18 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "NodeListDim.h"
#include "NodeDim.h"

namespace formulae{ namespace node {

dist_t hlistWidth(const hlist_t &list) {
  return std::accumulate(
      std::cbegin(list), std::cend(list), zero(),
      [](dist_t x, const NodeRef &y) -> dist_t { return x + width(y); });
}
dist_t hlistHeight(const hlist_t &list) {
  return std::accumulate(std::cbegin(list), std::cend(list), zero(),
                         [](dist_t x, const NodeRef &y) -> dist_t {
                           return std::max(x, height(y));
                         });
}
dist_t hlistDepth(const hlist_t &list) {
  return std::accumulate(std::cbegin(list), std::cend(list), zero(),
                         [](dist_t x, const NodeRef &y) -> dist_t {
                           return std::max(x, depth(y));
                         });
}
dist_t vlistWidth(const vlist_t &list) {
  return std::accumulate(std::cbegin(list), std::cend(list), zero(),
                         [](dist_t x, const NodeRef &y) -> dist_t {
                           return std::max(x, vwidth(y));
                         });
}
dist_t vlistVsize(const vlist_t &list) {
  return std::accumulate(
      std::cbegin(list), std::cend(list), zero(),
      [](dist_t x, const NodeRef &y) -> dist_t { return x + vsize(y); });
}}}