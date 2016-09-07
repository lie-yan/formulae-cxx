#pragma once

#include "BasicBox.h"
#include "BasicTypes.h"
#include "BoxTypes.h"
#include "HListGlue.h"
#include "NodeListDim.h"

namespace formulae{
namespace node {

dim_t desiredDimensions(dist_t w, const hlist_t &nl);
dim_t naturalDimensions(const hlist_t &nl);

template <typename HList = hlist_t>
box_t hpackNat(HList &&nl) {
  return hbox(naturalDimensions(nl), std::forward<HList>(nl));
}

template <typename HList = hlist_t>
box_t boxList(HList &&nl) {
  Expects(not nl.empty());

  const NodeRef & first = *nl.begin();
  if (nl.size() == 1 and
      first.tag()==NodeTag::Box and
      first.as<Box_t>().shift == zero()) {
    return first.as<Box_t>().box;
  } else {
    return hpackNat(std::forward<HList>(nl));
  }
}

/**
 * sets width to a given value, using glue adaptation
 * @param w
 * @param nl
 * @return
 */
template <typename HList = hlist_t> box_t setWidth(dist_t w, HList &&nl) {
  auto nw = hlistWidth(nl);
  auto dim = desiredDimensions(w, nl);
  return hlistGlue(dim, w - nw, std::forward<HList>(nl));
}

/**
 * increases width by a given value which may be negative,
 * using glue adaptation
 * @param dw
 * @param nl
 * @return
 */
template <typename HList = hlist_t> box_t increaseWidth(dist_t dw, HList &&nl) {
  auto nw = hlistWidth(nl);
  auto dim = desiredDimensions(nw + dw, nl);
  return hlistGlue(dim, dw, std::forward<HList>(nl));
}


// `transfer(...)` is used by `rebox(...)` only
void transfer(nlist_t &to, const box_t &from);
void transfer(nlist_t &to, box_t &&from);

template <typename Box = box_t>
box_t rebox(dist_t newWidth, Box && b) {

  if (newWidth == b.width()) {
    return std::forward<Box>(b);
  } else if (b.content.empty()) {
    return hpackNat(hlist_t{Kern_t::create(newWidth)});
  } else {
    auto glue = Glue_t::create(ssGlue());
    auto dim = dim_t{newWidth, b.height(), b.depth()};

    auto hl = hlist_t{glue};
    auto bWidth = b.width();
    if (b.kind == boxkind_t::VBox) {
      hl.push_back(Box0(std::forward<Box>(b)));
    } else {
      transfer(hl, std::forward<Box>(b));
    }
    hl.push_back(glue);
    return hlistGlue(dim, newWidth - bWidth, hl);
  }
}
}
}