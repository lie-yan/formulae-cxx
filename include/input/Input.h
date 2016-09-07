#pragma once


#include <string>
#include "MathTypes.h"

namespace formulae {
namespace input {


math::mlist_t trans(const std::string &str);

template<typename ML=math::mlist_t>
math::NoadRef overline(ML &&ml) {
  return math::Overline_t::create(std::forward<ML>(ml));
}

template<typename ML=math::mlist_t>
math::NoadRef underline(ML &&ml) {
  return math::Underline_t::create(std::forward<ML>(ml));
}


template<typename MLnum=math::mlist_t, typename MLden=math::mlist_t>
math::NoadRef fraction(MLnum &&num, MLden &&den) {
  math::genfraction_t fract {std::forward<MLnum>(num),
                             std::forward<MLden>(den),
                             boost::none,
                             delim_t(0),
                             delim_t(0)};
  return math::GenFraction_t::create(std::move(fract));
};


template<typename MLtop=math::mlist_t, typename MLbot=math::mlist_t>
math::NoadRef atop(MLtop &&top, MLbot &&bot) {
  math::genfraction_t fract{std::forward<MLtop>(top),
                            std::forward<MLbot>(bot),
                            optional<dist_t>(zero()),
                            delim_t(0),
                            delim_t(0)};
  return math::GenFraction_t::create(std::move(fract));
};

template<typename MLnuc=math::mlist_t, typename MLsup=math::mlist_t>
math::NoadRef sup(MLnuc &&nuc, MLsup &&supBox) {
  math::script_t script{std::forward<MLnuc>(nuc),
                         std::forward<MLsup>(supBox),
                         boost::none};
  return math::Script_t::create(std::move(script));
};

template<typename MLnuc=math::mlist_t, typename MLsub=math::mlist_t>
math::NoadRef sub(MLnuc &&nuc, MLsub &&subBox) {
  math::script_t script{std::forward<MLnuc>(nuc),
                         boost::none,
                         std::forward<MLsub>(subBox)};
  return math::Script_t::create(std::move(script));
};

template<typename MLnuc=math::mlist_t, typename MLsup=math::mlist_t, typename MLsub=math::mlist_t>
math::NoadRef supsub(MLnuc &&nuc, MLsup &&sup, MLsub &&sub) {
  math::script_t script{std::forward<MLnuc>(nuc),
                         std::forward<MLsup>(sup),
                         std::forward<MLsub>(sub)};
  return math::Script_t::create(std::move(script));
}

const math::NoadRef sumsym = math::MathChar_t::create(math::kind_t::Op, family_t::EX, charCode_t(80));
const math::NoadRef intsym = math::MathChar_t::create(math::kind_t::Op, family_t::EX, charCode_t(82));

template<typename MLnuc=math::mlist_t,
    typename OptMLsup=optional<math::mlist_t>,
    typename OptMLsub=optional<math::mlist_t >>
math::NoadRef BigOp(MLnuc &&nuc, OptMLsup &&supOpt, OptMLsub &&subOpt) {
  math::script_t script {std::forward<MLnuc>(nuc),
                         std::forward<OptMLsup>(supOpt),
                         std::forward<OptMLsub>(subOpt)};
  return math::BigOp_t::create(math::limits_t::Default, std::move(script));
};

template<typename OptMLsub=optional<math::mlist_t>, typename OptMLsup=optional<math::mlist_t >>
math::NoadRef sum(OptMLsub &&subOpt, OptMLsup &&supOpt) {
  return BigOp(math::mlist_t{sumsym},
               std::forward<OptMLsub>(supOpt),
               std::forward<OptMLsup>(subOpt));
};

template<typename OptMLsub=optional<math::mlist_t>, typename OptMLsup=optional<math::mlist_t >>
math::NoadRef integral(OptMLsub &&subOpt, OptMLsup &&supOpt) {
  return BigOp(math::mlist_t{intsym},
               std::forward<OptMLsub>(supOpt),
               std::forward<OptMLsup>(subOpt));
};

template<typename ML=math::mlist_t>
math::NoadRef math(math::kind_t kind, ML &&ml) {
  return math::Kind_t::create(kind, std::forward<ML>(ml));
}

math::NoadRef style(style_t st);
math::NoadRef choice(const math::mlist_t &d,
                    const math::mlist_t &t,
                    const math::mlist_t &s,
                    const math::mlist_t &ss);
}
}