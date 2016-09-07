/**
 * Created: Wed Aug 31 17:13:25 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

namespace formulae{
namespace math{

enum class kind_t {
  Ord,
  Op,
  Bin,
  Rel,
  Open,
  Close,
  Punct,
  Inner,
  None,
};

enum class limits_t {
  Default,
  Yes,
  No,
};

}
}