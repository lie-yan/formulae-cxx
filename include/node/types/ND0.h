/**
 * Created: Wed Aug 31 19:49:36 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

namespace formulae{ namespace node {

enum class infOrder_t {
  normal,
  fil,
  fill,
  filll,
};

class glueParam_t {
public:
  enum class Tag {
    natural,
    stretching,
    shrinking,
  };

  glueParam_t(Tag tag = Tag::natural, real_t real = real_t(0.0),
              const infOrder_t &ord = infOrder_t::normal)
      : tag(tag), factor(real), ord(ord) {}

  static glueParam_t natural() { return glueParam_t{Tag::natural}; }
  static glueParam_t stretching(real_t real, const infOrder_t &ord) {
    return glueParam_t{Tag::stretching, real, ord};
  }
  static glueParam_t shrinking(real_t real, const infOrder_t &ord) {
    return glueParam_t{Tag::shrinking, real, ord};
  }

public:
  Tag tag;
  real_t factor;
  infOrder_t ord;
};

struct glueSpec_t {
  struct subSpec_t {
    dist_t dist;
    infOrder_t infOrder;
  };

  dist_t size;
  subSpec_t stretch;
  subSpec_t shrink;
};

class dim_t {
public:
  dim_t(dist_t width = zero(), dist_t height = zero(),
        dist_t depth = zero())
      : _width(width), _height(height), _depth(depth) {}

  inline dist_t width() const { return _width; }
  inline dist_t height() const { return _height; }
  inline dist_t depth() const { return _depth; }

private:
  dist_t _width;
  dist_t _height;
  dist_t _depth;
};

enum class boxkind_t {
  HBox,
  VBox,
};}}