/**
 * Last modified: Tue Aug 30 19:51:18 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"
#include "BoxTypes.h"
namespace formulae{ namespace node {

dist_t hlistWidth(const hlist_t &list);
dist_t hlistHeight(const hlist_t &list);
dist_t hlistDepth(const hlist_t &list);
dist_t vlistWidth(const vlist_t &list);
dist_t vlistVsize(const vlist_t &list);}}