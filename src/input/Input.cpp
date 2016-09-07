#include "Input.h"


#include <string>
#include "MathTypes.h"
#include "General.h"

using namespace formulae::math;

namespace formulae {
namespace input {

std::tuple<kind_t, family_t, int>
sym(int ch) {

  using namespace std::string_literals;
  static const std::string punct = "!?;";
  if (isalpha(ch)) {
    return std::make_tuple(kind_t::Ord, family_t::MI, ch);
  } else if (isdigit(ch) or ch == '@') {
    return std::make_tuple(kind_t::Ord, family_t::RM, ch);
  } else if (ch == '(' or ch == '[') {
    return std::make_tuple(kind_t::Open, family_t::RM, ch);
  } else if (ch == ')' or ch == ']') {
    return std::make_tuple(kind_t::Close, family_t::RM, ch);
  } else if (ch =='=' or ch == ':') {
    return std::make_tuple(kind_t::Rel, family_t::RM, ch);
  } else if (ch == '<' or ch == '>') {
    return std::make_tuple(kind_t::Rel, family_t::MI, ch);
  } else if (general::contains(punct, ch)) {
    return std::make_tuple(kind_t::Punct, family_t::RM, ch);
  } else {
    switch(ch){
      case ',': return std::make_tuple(kind_t::Punct, family_t::MI, 59);
      case '+': return std::make_tuple(kind_t::Bin, family_t::RM, 43);
      case '-': return std::make_tuple(kind_t::Bin, family_t::SY, 0);
      case '*': return std::make_tuple(kind_t::Bin, family_t::SY, 3);
      case '.': return std::make_tuple(kind_t::Bin, family_t::SY, 1);
      default:
        throw  NotImplemented{};
    }
  }
}

math::mlist_t trans(const std::string &str) {
  math::mlist_t ret;
  std::transform(str.begin(), str.end(), std::back_inserter(ret),
                 [](int ch){
                   kind_t  kind; family_t  fam; int code;
                   std::tie(kind, fam, code) = sym(ch);
                   return MathChar_t::create(kind, fam, charCode_t(code));
                 });
  return ret;
}

math::NoadRef style(style_t st) {
  return math::Style_t::create(st);
}

math::NoadRef choice(const math::mlist_t  & d,
                    const math::mlist_t  & t,
                    const math::mlist_t  & s,
                    const math::mlist_t  & ss) {

  return math::Choice_t::create([d, t, s, ss](style_t st) {
    if (st == style_t::Display)
      return d;
    else if (st == style_t::Text)
      return t;
    else if (st == style_t::Script)
      return s;
    else if (st == style_t::Scriptscript)
      return ss;
    else
      throw CannotHappen{};
  });

}



}
}