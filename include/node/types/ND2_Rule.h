/**
 * Created: Wed Aug 31 19:56:59 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "ND0.h"
#include "ND1_Box.h"

namespace formulae{ namespace node {

class Rule_t : public Node {
public:
  virtual ~Rule_t() = default;
  
  inline virtual NodeTag tag() const override { return NodeTag::Rule; }
  inline virtual gsl::owner<Rule_t *> clone() const override {
    return new Rule_t(*this);
  }
  
  inline virtual dist_t width() const override { return this->dim.width(); }
  inline virtual dist_t height() const override { return this->dim.height(); }
  inline virtual dist_t depth() const override { return this->dim.depth(); }
  inline virtual dist_t vwidth() const override { return this->dim.width(); }
  inline virtual dist_t vsize() const override {
    return this->dim.height() + this->dim.depth();
  }

  static NodeRef create(dim_t dim) { return NodeRef(new Rule_t(dim)); }

protected:
  Rule_t(dim_t dim) : dim{dim} {}
public:
  dim_t dim;
};}}