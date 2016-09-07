#pragma once

#include "IListTranslate.h"
#include "MathTranslate.h"

namespace formulae {

template<typename MList=math::mlist_t>
node::hlist_t displayFormula(MList && ml) {
  return translate::MListToHList(style_t::Display, false, false, std::forward<MList>(ml));
}

template <typename MList=math::mlist_t>
node::hlist_t inlineFormual(MList && ml) {
  return translate::MListToHList(style_t::Text, false, true, std::forward<MList>(ml));
}

}