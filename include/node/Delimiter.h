#pragma once

#include "BoxTypes.h"

namespace formulae{
namespace node {
  
  NodeRef varDelimiter(style_t  st, dist_t  delimiterSize, delim_t  delim);
  NodeRef makeDelimiter(style_t  st, delim_t  delim);
}
}