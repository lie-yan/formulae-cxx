#include "ShipOut.h"
#include "SetBox.h"
#include "Out.h"

using namespace formulae::node;

namespace formulae {
namespace dvi {

const int mag = 2000;
const dist_t lineSkip = distInt(20);

static void lines(const list_t<hlist_t > & hlists) {
  if (hlists.empty())
    return;
  else {
    auto it = std::begin(hlists);
    setHList(*it);
    advance(it, 1);
    for (auto e = std::end(hlists); it!=e; advance(it, 1)) {
      Down(lineSkip);
      setHList(*it);
    }
  }
}

void shipOut(const list_t<hlist_t > & hlists) {
  std::cout << "Start shipping out...";
  startOut("this.dvi");
  Pre(mag);
  Bop();
  lines(hlists);
  Eop();
  Post(mag);
  endOut();
  std::cout << "End.\n";
}

}
}