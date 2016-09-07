
#include "MathSpace.h"
#include "StyleParams.h"

namespace formulae {
namespace math {

using node::glueSpec_t;
using subSpec_t = node::glueSpec_t::subSpec_t;

static node::NodeRef transSpace(const SpaceRef &sp) {
  switch (sp.tag()) {
    case SpaceTag::SKern:
      return node::Kern_t::create(sp.as<SKern_t>().size);
    case SpaceTag::SGlue:
      return node::Glue_t::create(sp.as<SGlue_t>().spec);
  }
}

static subSpec_t conv(dist_t m, subSpec_t sp) {
  if (sp.infOrder == node::infOrder_t::normal)
    return subSpec_t{dist_t(m.value() * sp.dist.value()), sp.infOrder};
  else
    return sp;
}

static node::NodeRef convert(dist_t m, const SpaceRef &sp) {
  switch (sp.tag()) {
    case SpaceTag::SKern:
      return node::Kern_t::create(dist_t(m.value() * sp.as<SKern_t>().size.value()));

    case SpaceTag::SGlue: {
      auto& glue  =sp.as<SGlue_t>();
      auto size = dist_t(m.value() * glue.spec.size.value());
      auto stretch = conv(m, glue.spec.stretch);
      auto shrink = conv(m, glue.spec.shrink);
      return node::Glue_t::create(glueSpec_t{size, stretch, shrink});
    }
  }
}

node::hlist_t makeSpace(style_t st, const mathSpace_t &ms) {
  if (ms.always or st == style_t::Display or st == style_t::Text) {
    return {ms.isMu ? convert(font::MathUnit(st), ms.entry)
                    : transSpace(ms.entry)};
  } else {
    return {};
  }
}

node::hlist_t makeSpaceOpt(style_t st, const optional<mathSpace_t> &ms) {
  if (ms)
    return makeSpace(st, ms.value());
  else
    return {};
}
}
}