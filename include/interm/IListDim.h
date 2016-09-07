/**
 * Last modified: Wed Aug 31 12:34:37 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BoxTypes.h"
#include "IListTypes.h"
#include "NodeListDim.h"
#include <functional>

namespace formulae {
namespace interm {

dist_t ilistHeight(const ilist_t &list);
dist_t ilistDepth(const ilist_t &list);

}// namespace
}