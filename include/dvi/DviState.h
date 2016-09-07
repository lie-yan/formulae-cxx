#pragma once

#include "BasicTypes.h"
#include "FontTypes.h"

namespace formulae {
namespace dvi {

dist_t getX();
void moveX(dist_t dist);
void resetX();

dist_t getY();
void moveY(dist_t dist);
void resetY();

bool sameFont(fontNr_t nr);
void setFont(fontNr_t nr);
void resetFont();

bool isDefined(fontNr_t nr);
void addFont(fontNr_t nr);
list_t<fontNr_t> definedFonts();

int actPage();
void nextPage();

int prevPos();
int actPos();
void markPos();

void incLevel();
void decLevel();
int maxLevel();

void initState();

dist_t getX();
}
}