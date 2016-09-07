#pragma once

#include "FontTypes.h"

namespace formulae {
namespace dvi {

void SetChar(fontNr_t, charCode_t);
void PutChar(fontNr_t, charCode_t);
void SetRule(dist_t, dist_t);
void PutRule(dist_t, dist_t);
void Left(dist_t);
void Right(dist_t);
void Up(dist_t);
void Down(dist_t);
void Push();
void Pop();
void Bop();   // begin of page
void Eop();   // end of page
void Pre(int);
void Post(int);

}
}