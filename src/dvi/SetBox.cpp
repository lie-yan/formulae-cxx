#include "BoxPack.h"
#include "SetBox.h"

using namespace formulae::node;

namespace formulae {
namespace dvi {

void setNode(boxkind_t kind, glueParam_t gp, const NodeRef &node) {
  if (node.tag() == NodeTag::Char) {
    auto& ch = node.as<Char_t>();
    outChar(kind, ch.fontNr, ch.charCode);
  } else if (kind == boxkind_t::HBox and node.tag() == NodeTag::Box) {
    auto& box = node.as<Box_t>();
    Down(box.shift);
    setBox(kind, box.box);
    Up(box.shift);
  } else if (kind == boxkind_t::VBox and node.tag() == NodeTag::Box) {
    auto& box = node.as<Box_t>();
    Right(box.shift);
    setBox(kind, box.box);
    Left(box.shift);
  } else if (node.tag() == NodeTag::Rule) {
    outRule(kind, node.as<Rule_t>().dim);
  } else if (node.tag() == NodeTag::Glue) {
    outGlue(kind, gp, node.as<Glue_t>().glue);
  } else if (node.tag() == NodeTag::Kern) {
    outKern(kind, node.as<Kern_t>().size);
  } else {
    // nop
  }
}

void setList(boxkind_t kind, glueParam_t gp, const list_t<NodeRef> &list) {
  for (const auto & node : list) {
    setNode(kind, gp, node);
  }
}

void setBox(boxkind_t outerKind, const box_t &box) {
  if (outerKind == box.kind) {
    setList(box.kind, box.glueParam, box.content);
  } else if (outerKind == boxkind_t::HBox) {
    Up(box.height());
    setList(box.kind, box.glueParam, box.content);
    Up(box.depth());
    Right(box.width());
  } else {
    Down(box.height());
    setList(box.kind, box.glueParam, box.content);
    Down(box.depth());
    Left(box.width());
  }
}
void setHList(const hlist_t & list) {
  setBox(boxkind_t::VBox, boxList(list));
}

}
}