/**
 * Created: Wed Aug 31 19:56:59 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "ND0.h"

namespace formulae{ namespace node {

class Char_t : public Node {
public:
  virtual ~Char_t() = default;

  virtual NodeTag tag() const override { return NodeTag::Char; }
  virtual dist_t width() const override {
    return font::charWidth(this->fontNr, this->charCode);
  }
  virtual dist_t height() const override {
    return font::charHeight(this->fontNr, this->charCode);
  }
  virtual dist_t depth() const override {
    return font::charDepth(this->fontNr, this->charCode);
  }
  virtual dist_t vwidth() const override {
    return font::charWidth(this->fontNr, this->charCode);
  }
  virtual dist_t vsize() const override {
    return font::charHeight(this->fontNr, this->charCode) +
           font::charDepth(this->fontNr, this->charCode);
  }
  virtual gsl::owner<Char_t *> clone() const override {
    return new Char_t(*this);
  }

  static NodeRef create(fontNr_t fontNr, charCode_t charCode) {
    return NodeRef(new Char_t(fontNr, charCode));
  }

protected:
  Char_t(fontNr_t fontNr, charCode_t charCode)
      : fontNr{fontNr}, charCode(charCode) {}

public:
  fontNr_t fontNr;
  charCode_t charCode;
};}}