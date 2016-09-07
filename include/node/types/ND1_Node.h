/**
 * Created: Wed Aug 31 19:53:42 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "ND0.h"

namespace formulae{ namespace node {

enum class NodeTag {
  Char,
  Box,
  Rule,
  Glue,
  Kern,
  Penalty,
  Uninitialized,
};

class Node {
public:

  
  virtual ~Node() = default;
  virtual NodeTag tag() const = 0;
  virtual gsl::owner<Node *> clone() const = 0;
  
  inline virtual dist_t width()  const { return zero(); }
  inline virtual dist_t height() const { return zero(); }
  inline virtual dist_t depth()  const { return zero(); }
  inline virtual dist_t vwidth() const { return zero(); }
  inline virtual dist_t vsize()  const { return zero(); }
};

class NodeRef {
public:
  NodeRef(gsl::owner<Node*> node) : _node(node) {}
  NodeRef(const NodeRef &rhs) { _node.reset(rhs._node->clone()); }
  NodeRef &operator=(const NodeRef &rhs) {
    _node.reset(rhs._node->clone());
    return *this;
  }
  
  NodeRef()                         = default;
  NodeRef(NodeRef &&rhs)            = default;
  NodeRef &operator=(NodeRef &&rhs) = default;
  virtual ~NodeRef()                = default;

  inline NodeTag tag()     const { return _node->tag();    }
  inline dist_t width()    const { return _node->width();  }
  inline dist_t height()   const { return _node->height(); }
  inline dist_t depth()    const { return _node->depth();  }
  inline dist_t vwidth()   const { return _node->vwidth(); }
  inline dist_t vsize()    const { return _node->vsize();  }

  template <typename T>
  T& as() const { return *dynamic_cast<T*>(_node.get()); }

private:
  std::unique_ptr<Node> _node;
};

using nlist_t = list_t<NodeRef>;
using hlist_t = list_t<NodeRef>;
using vlist_t = list_t<NodeRef>;
}
}