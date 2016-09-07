/**
 * 
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"
#include "BoxTypes.h"
#include <exception>

namespace formulae{ namespace node {

// cannot stretch / shrink
class Rigid: std::exception{ };


/**
 * Given an access function (#stretch or #shrink),
 * the relevant glue information is extracted from a node list
 */
list_t<glueSpec_t::subSpec_t>
extractGlue(std::function<glueSpec_t::subSpec_t(glueSpec_t)> access,
            const list_t<NodeRef> & list);

/**
 * This function adds up the glue values of the given infinity order
 *
 */
dist_t addGlue(const infOrder_t & ord, const list_t<glueSpec_t::subSpec_t> & list);

/**
 * This function adds up the glue values in the list,
 * separately by the infOrder,
 * and returns the highest order where the sum does not cancel out to zero
 * and this sum
 *
 */
glueSpec_t::subSpec_t totalGlue(const list_t<glueSpec_t::subSpec_t> &gl);

/**
 * computes the glue parameter resulting from changing the natural size
 * of the node list by the given amount
 *
 */
glueParam_t getGlueParam(dist_t  dw, const list_t<NodeRef> & nl);}}