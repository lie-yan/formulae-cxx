/**
 * Last modified: Tue Aug 30 19:53:39 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "NodeDim.h"

namespace formulae{ namespace node {

dist_t width(const NodeRef &node) { return node.width(); }
dist_t height(const NodeRef &node) { return node.height(); }
dist_t depth(const NodeRef &node) { return node.depth(); }
dist_t vwidth(const NodeRef &node) { return node.vwidth(); }
dist_t vsize(const NodeRef &node) { return node.vsize(); }}}