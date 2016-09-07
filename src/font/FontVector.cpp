/**
 * Last modified: Tue Aug 30 18:39:11 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#include "FontVector.h"
#include "LoadFont.h"

namespace formulae {

namespace GV {
std::vector<famSizePair_t> famSizeVector;
std::vector<fontNr_t> fontNumberVector;
std::vector<font_t> fontVector;
}

namespace font {

std::tuple<list_t<fontNr_t>, list_t<famSizePair_t>>
number(const list_t<famSizePair_t> &list) {
  list_t<std::pair<famSizePair_t, int>> elems;

  int count = 0;
  std::transform(
      std::begin(list), std::end(list), std::back_inserter(elems),
      [&count](const auto &x) { return std::make_pair(x, count++); });

  std::sort(std::begin(elems), std::end(elems));

  list_t<famSizePair_t> vec;
  list_t<fontNr_t> nums(list.size(), fontNr_t{0});

  count = -1;
  for (const auto &p : elems) {
    if (vec.empty() or vec.back() != p.first) {
      vec.push_back(p.first);
      nums[p.second] = fontNr_t{++count};
    } else {
      nums[p.second] = fontNr_t{count};
    }
  }
  return std::make_tuple(nums, vec);
};

class initialize_font_settings_auto final {
public:
  initialize_font_settings_auto() { init(); }

protected:
  std::tuple<list_t<fontNr_t>, list_t<famSizePair_t>> genFamSizePairs() {
    auto fam = list_t<family_t>{family_t::RM, family_t::MI, family_t::SY,
                                family_t::EX}; // the order matters
    auto sty = list_t<style_t>{style_t::Display, style_t::Text, style_t::Script,
                               style_t::Scriptscript}; // the order matters
    auto famStyleList = prod(fam, sty);

    using famStylePair_t = std::tuple<family_t, style_t>;
    using famSizePair_t = std::tuple<family_t, fsize_t>;
    list_t<famSizePair_t> famSizeList;
    std::transform(std::begin(famStyleList), std::end(famStyleList),
                   std::back_inserter(famSizeList),
                   [](const famStylePair_t &p) {
                     family_t fam;
                     style_t sty;
                     std::tie(fam, sty) = p;
                     return std::make_tuple(fam, size(fam, sty));
                   });

    return number(famSizeList);
  }

  void init() {
    if (not done) {
      done = true;
//      std::cout << "initialize_font_settings_auto::init()\n";
      std::tie(GV::fontNumberVector, GV::famSizeVector) = genFamSizePairs();

      // load the font vector
      std::transform(std::begin(GV::famSizeVector), std::end(GV::famSizeVector),
                     std::back_inserter(GV::fontVector),
                     [](const famSizePair_t &p) {
                       return loadFont(std::get<0>(p), std::get<1>(p));
                     });

      Ensures(not GV::fontNumberVector.empty());
      Ensures(not GV::famSizeVector.empty());
      Ensures(not GV::fontVector.empty());
    }
  }

private:
  static bool done;
};

bool initialize_font_settings_auto::done = false;
static const initialize_font_settings_auto gInitialize_font_settings_auto;
}
}
