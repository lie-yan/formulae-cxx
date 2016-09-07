/**
 *
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"

namespace formulae {
namespace font {

constexpr fsize_t size(family_t fam, style_t style) {
  if (style == style_t::Display)
    return fsize_t{10};
  else if (style == style_t::Text)
    return fsize_t{10};
  else if (fam == family_t::EX)
    return fsize_t{10};
  else if (style == style_t::Script)
    return fsize_t{7};
  else if (style == style_t::Scriptscript)
    return fsize_t{5};
  else
    throw CannotHappen{};
}

}
}