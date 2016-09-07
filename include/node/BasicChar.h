#pragma once

#include "BasicTypes.h"
#include "BoxTypes.h"

namespace formulae{
namespace node {

std::tuple<NodeRef, dist_t> basicChar(style_t st, bool enlarge, family_t fam,
                                     charCode_t ch);

}
}