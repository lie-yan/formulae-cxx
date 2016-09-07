#include "Out.h"
#include "DviState.h"

#include "FontTypes.h"
#include "General.h"

using formulae::general::contains;

namespace formulae {
namespace dvi{

static void incr(int n, int & r) { r += n; }
static void inc(int & r) { incr(1, r); }
static void dec(int & r) { incr(-1, r); }

static int xMove = 0;
dist_t getX() { return dist_t(xMove); }
void moveX(dist_t dx) { incr(dx.value(), xMove); }
void resetX() { xMove = 0; }

static int yMove = 0;
dist_t getY() { return dist_t(yMove); }
void moveY(dist_t  dy) { incr(dy.value(), yMove); }
void resetY() { yMove = 0; }

static const fontNr_t noFont = fontNr_t{-1};
static fontNr_t actFont = noFont;
bool sameFont(fontNr_t nr) { return nr==actFont; }
void setFont(fontNr_t nr) { actFont = nr; }
void resetFont() { actFont = noFont; }

static list_t<fontNr_t > fontList;
bool isDefined(fontNr_t nr) {
  return contains(fontList, nr);
}
void addFont(fontNr_t nr) {
  fontList.push_back(nr);
}
list_t<fontNr_t>  definedFonts() {
  return fontList;
}

static int pageNr = 0;
int actPage() { return pageNr; }
void nextPage() { inc(pageNr); }

static int oldPos = -1;
static int newPos = -1;
int prevPos() { return oldPos; }
int actPos() { return newPos; }
void markPos() { oldPos = newPos; newPos = outPos();}


static int ActLevel = 0;
static int MaxLevel = 0;

void incLevel() {
  inc(ActLevel);
  if (ActLevel > MaxLevel)
    inc(MaxLevel);
}
void decLevel() { dec(ActLevel); }
int maxLevel() { return MaxLevel; }

void initState() {
  xMove = 0;
  yMove = 0;
  actFont = noFont;
  fontList = {};
  pageNr = 0;
  oldPos = -1;
  newPos = -1;
  ActLevel = 0;
  MaxLevel = 0;
}

}
}