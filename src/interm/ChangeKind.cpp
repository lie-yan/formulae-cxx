#include "ChangeKind.h"

using kind_t = formulae::math::kind_t;
using namespace formulae::general;

namespace formulae {
namespace interm {

static kind_t listKind(gsl::span<ItemRef> list) {
  for (const auto &elem : list) {
    if (elem.tag() == ItemTag::INoad)
      return elem.as<INoad_t>().kind;
  }
  return kind_t::None;
}

static bool checkPrev(kind_t k) {
  static const std::vector<kind_t> list{kind_t::Bin, kind_t::Op, kind_t::Rel,
                                        kind_t::Open, kind_t::Punct, kind_t::None};
  return contains(list, k);
}

static bool checkNext(kind_t k) {
  static const std::vector<kind_t> list{kind_t::Rel, kind_t::Close, kind_t::Punct, kind_t::None};
  return contains(list, k);
}


math::kind_t changeKind(math::kind_t prevKind, math::kind_t kind,
                        gsl::span<ItemRef> rest) {
  if (kind == kind_t::Bin) {
    return (checkPrev(prevKind) or checkNext(listKind(rest))) ? kind_t::Ord
                                                              : kind_t::Bin;
  } else {
    return kind;
  }
}
}
}