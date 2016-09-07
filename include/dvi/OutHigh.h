#pragma once

#include <string>

namespace formulae {
namespace dvi {

void outChar(char c);
void outStr(const std::string &str); // the nake string
void outString(const std::string &str); // the wrapped string
void outNat1(int x);
void outNat2(int x);
void outInt4(int x);
void outZero(int n);
void outInstrV(int code, int n);

}
}