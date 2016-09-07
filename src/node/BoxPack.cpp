#include "BoxPack.h"
#include "HListGlue.h"
#include "NodeListDim.h"

namespace formulae{ namespace node {

dim_t desiredDimensions(dist_t w, const hlist_t &nl) {
  return dim_t{w, hlistHeight(nl), hlistDepth(nl)};
}

dim_t naturalDimensions(const hlist_t &nl) {
  return desiredDimensions(hlistWidth(nl), nl);
}

void transfer(nlist_t &to, const box_t &from) {
  to.insert(std::end(to), std::begin(from.content), std::end(from.content));
}

void transfer(nlist_t &to, box_t &&from) {
  to.insert(std::end(to), std::make_move_iterator(from.content.begin()),
            std::make_move_iterator(from.content.end()));
}}}