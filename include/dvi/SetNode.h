#pragma once


#include <BoxTypes.h>

namespace formulae {
namespace dvi {

void outChar(node::boxkind_t, fontNr_t , charCode_t );
void outRule(node::boxkind_t, node::dim_t );
void outKern(node::boxkind_t, dist_t );
void outGlue(node::boxkind_t, node::glueParam_t , node::glueSpec_t );

}
}