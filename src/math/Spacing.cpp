/**
 * Created: Wed Aug 31 20:56:24 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "Spacing.h"
#include "MathGlue.h"

namespace formulae {
namespace math {

optional<mathSpace_t> mathSpacing(kind_t left, kind_t right) {
  if (left == kind_t::None)
    return noSkip;
  else if (right == kind_t::None)
    return noSkip;
  else if (left == kind_t::Bin)
    return medSkip1;
  else if (left == kind_t::Open)
    return noSkip;
  else if (left == kind_t::Punct)
    return thinSkip1;
  else if (right == kind_t::Bin)
    return medSkip1;
  else if (right == kind_t::Close)
    return noSkip;
  else if (left == kind_t::Rel and right == kind_t::Rel)
    return noSkip;
  else if (left == kind_t::Rel and right == kind_t::Punct)
    return noSkip;
  else if (left == kind_t::Rel)
    return thickSkip1;
  else if (right == kind_t::Rel)
    return thickSkip1;
  else if (right == kind_t::Op)
    return thinSkip;
  else if (right == kind_t::Inner)
    return thinSkip1;
  else if (left == kind_t::Inner)
    return thinSkip1;
  else if (left == kind_t::Op and right == kind_t::Ord)
    return thinSkip;
  else
    return noSkip;
}
}
}
