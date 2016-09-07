#include "SetNode.h"
#include "OutHigh.h"
#include "DviCmd.h"


using namespace formulae::node;
using namespace formulae::font;

namespace formulae {
namespace dvi {


void outChar(boxkind_t kind, fontNr_t fn, charCode_t ch) {
  if (kind == boxkind_t::HBox) {
    SetChar(fn, ch);
  } else if (kind == boxkind_t::VBox) {
    Down(charHeight(fn, ch));
    PutChar(fn, ch);
    Down(charDepth(fn, ch));
  } else {
    throw CannotHappen{};
  }
}

void outRule(boxkind_t kind, dim_t dim) {
  if (kind == boxkind_t::HBox) {
    Down(dim.depth());
    SetRule(dim.height() + dim.depth(), dim.width());
    Up(dim.depth());
  } else if (kind == boxkind_t::VBox) {
    auto vsize = dim.height() + dim.depth();
    Down(vsize);
    PutRule(vsize, dim.width());
  } else {
    throw CannotHappen{};
  }
}

void outKern(boxkind_t kind, dist_t dist) {
  if (kind == boxkind_t::HBox)
    Right(dist);
  else if (kind == boxkind_t::VBox) {
    Down(dist);
  } else {
    throw CannotHappen{};
  }
}

dist_t glueMult(real_t r, infOrder_t ord, dist_t d, infOrder_t ord1) {
  return ord == ord1 ? realMult(r, d) : zero();
}

dist_t glueMult(glueParam_t param, glueSpec_t::subSpec_t spec) {
  return param.ord == spec.infOrder ? realMult(param.factor, spec.dist) : zero();
}

dist_t glueSize(glueParam_t param, glueSpec_t spec) {
  using Tag = glueParam_t::Tag;
  switch (param.tag) {
    case Tag::natural:
      return spec.size;
    case Tag::stretching:
      return spec.size + glueMult(param, spec.stretch);
    case Tag::shrinking:
      return spec.size - glueMult(param, spec.shrink);
  }
}

void outGlue(boxkind_t kind, glueParam_t param, glueSpec_t spec) {
  outKern(kind, glueSize(param, spec));
}
}
}