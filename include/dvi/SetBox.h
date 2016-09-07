#pragma once

#include "BoxTypes.h"
#include "SetNode.h"
#include "DviCmd.h"
namespace formulae {
namespace dvi {

void setNode(node::boxkind_t kind, node::glueParam_t gp, const node::NodeRef &node);
void setList(node::boxkind_t kind, node::glueParam_t gp, const list_t<node::NodeRef> &list);
void setBox(node::boxkind_t kind, const node::box_t &box);
void setHList(const node::hlist_t &);

}
}