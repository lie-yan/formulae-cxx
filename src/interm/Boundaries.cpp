/**
 *
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "Boundaries.h"
#include "Const.h"
#include "StyleParams.h"
#include "Delimiter.h"
#include "IListDim.h"

namespace formulae{
namespace interm{

static dist_t delimiterSize(dist_t axisDist) {
  return std::max((axisDist / 500) * GV::delimiterFactor, // units of 1000
                  2 * axisDist - GV::delimiterShortfall);
}

std::tuple<node::NodeRef, node::NodeRef>
makeBoundaries(style_t st, dist_t height, dist_t depth,
               delim_t left, delim_t right) {
  auto axh = font::AxisHeight(st);
  auto axisDist = std::max(height - axh, depth + axh);
  auto delSize = delimiterSize(axisDist);
  auto leftNode = node::varDelimiter(st, delSize, left);
  auto rightNode = node::varDelimiter(st, delSize, right);
  return std::make_tuple(leftNode, rightNode);
}


}
}