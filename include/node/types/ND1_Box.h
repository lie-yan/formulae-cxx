/**
 * Created: Wed Aug 31 19:56:59 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "ND0.h"

namespace formulae{ namespace node {

class box_t {
public:
  template <typename NList = nlist_t>
  box_t(boxkind_t boxkind, dim_t dim = {},
        NList &&nl = {}, glueParam_t gp = {})
      : kind(boxkind),
        dim(dim),
        content(std::forward<NList>(nl)),
        glueParam(gp) {}

  box_t() = default;
  box_t(const box_t &)            = default;
  box_t(box_t &&)                 = default;
  box_t &operator=(const box_t &) = default;
  box_t &operator=(box_t &&)      = default;
  ~box_t()                        = default;

  inline dist_t width() const { return dim.width(); }
  inline dist_t height() const { return dim.height(); }
  inline dist_t depth() const { return dim.depth(); }

  template <typename NList>
  friend box_t makebox(const boxkind_t &boxkind, dim_t dim, NList &&nl);

public:
  boxkind_t kind;
  dim_t dim;
  nlist_t content;
  glueParam_t glueParam;
};}}