/**
 * Last modified: Tue Aug 30 19:03:58 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "LoadFont.h"
#include "Distance.h"
#include <fstream>

namespace formulae {
namespace font {

std::string famName(family_t fam) {
  using namespace std::string_literals;
  switch (fam) {
    case family_t::RM:
      return "RM";
    case family_t::MI:
      return "MI";
    case family_t::SY:
      return "SY";
    case family_t::EX:
      return "EX";
    default:
      throw CannotHappen("formulae::font::famName(...): this line of"
                             " code is not expected to be executed");
  }
}

std::string sizeExt(fsize_t s) {
  return std::to_string(s.value() / 10) + std::to_string(s.value() % 10);
}

std::string FileName(family_t fam, fsize_t s) {
  return famName(fam) + sizeExt(s);
}

optional<varCharInfo_t> varChar(const optional<charCode_t> &top,
                                const optional<charCode_t> &bot,
                                const optional<charCode_t> &rep) {
  if (top or bot or rep)
    return optional<varCharInfo_t>{varCharInfo_t{top, bot, rep}};
  else
    return optional<varCharInfo_t>{};
}

dist_t getDist(fsize_t size, std::istream &file) {
  std::string s;
  std::getline(file, s);
  return realMult(real_t{std::stod(s)},
                  distInt(size.value()));
}

charCode_t getCharCode(std::istream &file) {
  std::string s;
  std::getline(file, s);
  std::size_t pos = 0;
  return charCode_t{std::stoi(s, &pos, 8)}; // base 8
}

std::tuple<charInfo_t, bool> getInfo(fsize_t size, std::istream &file) {
  dist_t w = zero(), h = zero(), d = zero(), itCorr = zero();
  optional<charCode_t> larger, top, bot, rep;
  int code = 0;
  bool flag = true;
  while (flag) {
    switch (code = file.get()) {
      case 'W':
        w = getDist(size, file);
        break;
      case 'H':
        h = getDist(size, file);
        break;
      case 'D':
        d = getDist(size, file);
        break;
      case 'I':
        itCorr = getDist(size, file);
        break;
      case 'L':
        larger = optional<charCode_t>(getCharCode(file));
        break;
      case 'T':
        top = optional<charCode_t>(getCharCode(file));
        break;
      case 'B':
        bot = optional<charCode_t>(getCharCode(file));
        break;
      case 'R':
        rep = optional<charCode_t>(getCharCode(file));
        break;
      default:
        flag = false;
        break;
    }
  }
  return std::make_tuple(charInfo_t{w, h, d, itCorr, larger, varChar(top, bot, rep)},
                         code == 'E');
}

font_t getList(fsize_t size, std::istream &file) {
  font_t ret;
  bool eof = false;
  do {
    std::string str;
    std::getline(file, str); // eat the line containing 'C'

    charInfo_t info;
    std::tie(info, eof) = getInfo(size, file);
    ret.push_back(info);
  } while (not eof);
  return ret;
}

font_t loadFont(family_t fam, fsize_t s) {
  auto fileName = FileName(fam, s);
  auto file = std::ifstream{fileName};

  if (not file) {
    printf("File '%s' cannot be opened. Check the working directory.", fileName.c_str());
    std::exit(EXIT_FAILURE);
  }

  auto infoList = getList(s, file);
  return infoList;
}
}
}
