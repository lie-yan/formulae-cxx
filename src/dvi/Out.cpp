#include "Out.h"

namespace formulae {
namespace dvi {

static optional<std::fstream> out;

void startOut(const std::string &fileName) {
  std::fstream fs;
  fs.open(fileName, std::ios::out | std::ios::binary | std::ios::trunc);
  out = fs ? optional<std::fstream>(std::move(fs))
           : boost::none;
}

std::fstream &getStream() {
  return out ? out.value() : throw NoOut{};
}

void outByte(char b) {
  getStream().put(b);
}

std::fstream::pos_type outPos() {
  return getStream().tellp();
}

void endOut() {
  getStream().close();
}

}
}