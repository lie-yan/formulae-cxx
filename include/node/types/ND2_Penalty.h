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

class Penalty_t : public Node {
public:
  virtual ~Penalty_t() = default;

  virtual NodeTag tag() const override { return NodeTag::Penalty; }
  virtual gsl::owner<Penalty_t *> clone() const override {
    return new Penalty_t(*this);
  }

  static NodeRef create(penalty_t penalty) {
    return NodeRef(new Penalty_t(penalty));
  }


protected:
  Penalty_t(penalty_t penalty) : penalty{penalty} {}

private:
  penalty_t penalty;
};}}