#pragma once

#include "BasicTypes.h"
#include "FontTypes.h"
#include "OutHigh.h"

namespace formulae {
namespace dvi {

void setChar(charCode_t charCode);
void putChar(charCode_t charCode);
void setRule(dist_t a, dist_t b);
void putRule(dist_t a, dist_t b);
void right(dist_t d);
void down(dist_t d);
void push();
void pop();
void font(fontNr_t fn);
void fontDef(fontNr_t fontNr);
void fontDefs(const list_t<fontNr_t> &fn);
void bop(int pageNr, int prevPos);
void eop();
void pre(int mag);
void post(int mag, std::tuple<int, int, int> tup);
void postpost(int postPos);
void tail(int ownPos);

}
}