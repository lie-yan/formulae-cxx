
#include "BasicBox.h"
#include "BoxTypes.h"

namespace formulae {
namespace node {
NodeRef rule(dist_t h, dist_t w) {
  return Rule_t::create(dim_t{w, h, zero()});
}

glueSpec_t ssGlue() {
  auto fil1 = glueSpec_t::subSpec_t{one(), infOrder_t::fil};
  return glueSpec_t{zero(), fil1, fil1};
}

box_t emptyBox() { return hbox(dim_t{zero(), zero(), zero()}, nlist_t{}); }

hlist_t HL(const box_t &box) { return hlist_t{Box0(box)}; }
hlist_t HL(box_t &&box) { return hlist_t{Box0(std::move(box))}; }
}
}
