/**
 * Last modified: Tue Aug 30 18:50:36 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "BasicTypes.h"
#include "FontTypes.h"

namespace formulae {
namespace font {

fontNr_t fontNumber(style_t st, family_t fam); // return the internal font No. for (st, fam)
charCode_t larger(fontNr_t f, charCode_t ch); // return the charCode of `ch` in font No. `f`

}
}