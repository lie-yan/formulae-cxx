/**
 * Last modified: Tue Aug 30 19:53:39 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"
#include "BoxTypes.h"
namespace formulae{ namespace node {

dist_t width(const NodeRef &node);
dist_t height(const NodeRef &node);
dist_t depth(const NodeRef &node);
dist_t vwidth(const NodeRef &node);
dist_t vsize(const NodeRef &node);}}