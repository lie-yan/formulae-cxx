#pragma once

#include "BasicTypes.h"
#include "BoxTypes.h"


namespace formulae{ namespace node {


hlist_t makeChar(style_t  st, family_t  fam, charCode_t  ch);

std::tuple<NodeRef, dist_t, bool>
    makeNucChar(style_t  st, bool isOp, family_t  fam, charCode_t  ch);}}