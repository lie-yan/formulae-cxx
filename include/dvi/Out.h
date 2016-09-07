#pragma once

#include "BasicTypes.h"

#include <fstream>
#include <string>

namespace formulae {
namespace dvi {

class NoOut: public std::runtime_error {
public:
  NoOut(const std::string &what = "NoOut") : std::runtime_error(what) {}
};

void startOut(const std::string &fileName);
void endOut();
void outByte(char b);
std::fstream::pos_type outPos();

}
}