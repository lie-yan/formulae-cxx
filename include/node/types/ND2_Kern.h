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

class Kern_t : public Node {
public:
  virtual ~Kern_t() = default;
  
  
  inline virtual NodeTag tag() const override { return NodeTag::Kern; }
  inline virtual dist_t width() const override { return size; }
  inline virtual dist_t vsize() const override { return size; }
  inline virtual gsl::owner<Kern_t *> clone() const override {
    return new Kern_t(*this);
  }

  static NodeRef create(dist_t size) {
    return NodeRef(new Kern_t(size));
  }

protected:
  Kern_t(dist_t size) : size{size} {}
public:
  dist_t size;
};}}