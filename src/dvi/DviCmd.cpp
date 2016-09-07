#include "DviCmd.h"
#include "OutDvi.h"
#include "DviState.h"

namespace formulae {
namespace dvi {

void FontDef(fontNr_t f) {
  if (isDefined(f)) {
    // nop
  } else {
    fontDef(f);
    addFont(f);
  }
}

void Font(fontNr_t f) {
  if (sameFont(f)) {
    // nop
  } else {
    FontDef(f);
    font(f);
    setFont(f);
  }
}

void resetMove() {
  resetX();
  resetY();
}

void Move() {
  right(getX());
  down(getY());
  resetMove();
}

void Obj(const std::function<void()> &proc) {
  Move();
  proc();
}

void DoChar(fontNr_t f, const std::function<void()> &proc) {
  Font(f);
  Obj(proc);
}

void SetChar(fontNr_t f, charCode_t ch) {
  DoChar(f, [ch] { setChar(ch); });
}

void PutChar(fontNr_t f, charCode_t ch) {
  DoChar(f, [ch] { putChar(ch); });
}

void SetRule(dist_t a, dist_t b) {
  Obj([a, b] { setRule(a, b); });
}

void PutRule(dist_t a, dist_t b) {
  Obj([a, b] { putRule(a, b); });
}

void Left(dist_t dist) {
  moveX(- dist);
}

void Right(dist_t dist) {
  moveX(dist);
}

void Up(dist_t dist) {
  moveY(- dist);
}

void Down(dist_t dist) {
  moveY(dist);
}

void Push() {
  Move();
  push();
  incLevel();
}

void Pop() {
  resetMove();
  pop();
  decLevel();
}

void Bop() {
  markPos();
  nextPage();
  bop(actPage(), prevPos());
}

void Eop() {
  resetMove();
  resetFont();
  eop();
}

void Pre(int mag) {
  initState();
  pre(mag);
}

void Post(int mag) {
  markPos();
  post(mag, std::make_tuple(actPage(), prevPos(), maxLevel()));
  fontDefs(definedFonts());
  postpost(actPos());
  markPos();
  tail(actPos());
}

}
}