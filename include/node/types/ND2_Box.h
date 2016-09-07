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

struct Box_t : public Node {
public:
  
  Box_t(const Box_t &box)            = default;
  Box_t(Box_t &&box)                 = default;
  Box_t &operator=(const Box_t &rhs) = default;
  Box_t &operator=(Box_t &&rhs)      = default;
  virtual ~Box_t()                   = default;
  
  virtual NodeTag tag() const override { return NodeTag::Box; }
  virtual dist_t width() const override { return box.width(); }
  virtual dist_t height() const override {
    return box.height() - shift;
  }
  virtual dist_t depth() const override { return box.depth() + shift; }
  virtual dist_t vwidth() const override {
    return box.width() + shift;
  }
  virtual dist_t vsize() const override {
    return box.height() + box.depth();
  }
  virtual gsl::owner<Box_t *> clone() const override {
    return new Box_t(*this);
  }

  template <typename Box = box_t>
  static NodeRef create(Box &&box, dist_t shift=zero()) {
    return NodeRef(new Box_t(shift, std::forward<Box>(box)));
  }

protected:
  template<typename Box = box_t>
  Box_t(dist_t shift = zero(), Box && box = {})
  : shift{shift}, box{std::forward<Box>(box)} {}
  
public:
  dist_t shift; // shift amount
  box_t box;
};}}