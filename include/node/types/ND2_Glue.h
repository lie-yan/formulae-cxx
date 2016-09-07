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

class Glue_t : public Node {
public:
  
  virtual ~Glue_t() = default;
  
  virtual NodeTag tag() const override { return NodeTag::Glue; }
  virtual dist_t width() const override { return this->glue.size; }
  virtual dist_t vsize() const override { return this->glue.size; }
  virtual gsl::owner<Glue_t *> clone() const override {
    return new Glue_t(*this);
  }
  
  glueSpec_t glueSpec() const { return glue; }

  static NodeRef create(glueSpec_t glueSpec) {
    return NodeRef(new Glue_t(glueSpec));
  }

protected:
  Glue_t(glueSpec_t glueSpec) : glue{glueSpec} {}
public:
  glueSpec_t glue;
};}}