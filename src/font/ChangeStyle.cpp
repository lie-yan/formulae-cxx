/**
 * Last modified: Tue Aug 30 19:43:05 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "ChangeStyle.h"

namespace formulae {
namespace font {

style_t fract(style_t st) {
  switch (st) {
    case style_t::Display:
      return style_t::Text;
    case style_t::Text:
      return style_t::Script;
    default:
      return style_t::Scriptscript;
  }
}

style_t script(style_t st) {
  switch (st) {
    case style_t::Display:
    case style_t::Text:
      return style_t::Script;
    default:
      return style_t::Scriptscript;
  }
}
}
}