#include "OutDvi.h"

#include "Distance.h"
#include "FontVector.h"
#include "OutHigh.h"
#include "Out.h"

namespace formulae {
namespace dvi {

void instr(int n) {
  outNat1(n);
}

void instrArg(int code, int arg) {
  instr(code);
  outNat1(arg);
}

void setChar(charCode_t charCode) {
  int ch = charCode.value();
  if (ch < 128)
    instr (ch);
  else
    instrArg(128, ch);
}

void putChar(charCode_t charCode) {
  instrArg(133, charCode.value());
}

void rule(int code, int a, int b) {
  instr (code);
  outInt4(a);
  outInt4(b);
}

void setRule(dist_t a, dist_t b) {
  rule(132, a.value(), b.value());
}

void putRule(dist_t a, dist_t b) {
  rule(137, a.value(), b.value());
}

void right(dist_t d) {
  outInstrV(142, d.value());
}

void down(dist_t d) {
  outInstrV(156, d.value());
}

void push() {
  instr(141);
}
void pop() {
  instr(142);
}

void font(fontNr_t fn) {
  instr(171 + fn.value());
}

void fontDef(fontNr_t fontNr) {
  auto famSizePair = GV::famSizeVector[fontNr.value()];
  auto fam = std::get<0>(famSizePair);
  auto s   = std::get<1>(famSizePair);
  auto size = distInt(s.value());
  static const auto cmName = [](family_t fam) {
    if (fam == family_t::RM)
      return "cmr";
    else if (fam == family_t::MI)
      return "cmmi";
    else if (fam == family_t::SY)
      return "cmsy";
    else if (fam == family_t::EX)
      return "cmex";
    else
      throw CannotHappen{};
  };
  auto fileName = cmName(fam) + std::to_string(s.value());

  instrArg(243, fontNr.value());
  outZero(4);
  outInt4(size.value());
  outInt4(size.value());
  outZero(1);
  outString(fileName);
}

void fontDefs(const list_t<fontNr_t>& fn) {
  for (const auto x : fn) {
    fontDef(x);
  }
}

void bop(int pageNr, int prevPos) {
  instr (139);
  outInt4(pageNr);
  outZero(36);
  outInt4(prevPos);
}

void eop() {
  instr (140);
}

void version() {
  outNat1(2);
}
void numDen() {
  outInt4(25400000);
  outInt4(473628672);
}

void banner() {
  outString("Lie Yan's Formula Formatter");
}

void pre(int mag) {
  instr(247);
  version();
  numDen();
  outInt4(mag);
  banner();
}

void trailer(int n) {
  if (n == 0)
    return;
  else {
    instr (223);
    trailer(n-1);
  }
}

void post(int mag, std::tuple<int,int,int> tup) {
  int pageNr, prevPos, maxLevel;
  std::tie(pageNr, prevPos, maxLevel) = tup;
  instr(248);
  outInt4(prevPos);
  numDen();
  outInt4(mag);
  outInt4(distInt(10*72).value()); /* maxVSize */
  outInt4(distInt(7*72).value()); /* maxWidth */
  outNat2(maxLevel);
  outNat2(pageNr);
}

void postpost(int postPos) {
  instr (249);
  outInt4(postPos);
  version();
  trailer(3);
}

void tail(int ownPos) {
  trailer(4 - ownPos % 4);
}

}
}