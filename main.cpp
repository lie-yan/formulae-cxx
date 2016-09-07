//
//  main.cpp
//  formulae
//
//  Created by robin on 8/24/16.
//  Copyright © 2016 lie-yan. All rights reserved.
//

#include "formulae.h"
#include "Out.h"
#include "OutHigh.h"
#include "OutDvi.h"
#include "DviState.h"
#include "Input.h"
#include "ShipOut.h"

#include <node/BasicChar.h>

using namespace formulae;
using namespace formulae::node;
using namespace formulae::math;
using namespace formulae::dvi;
using namespace formulae::input;
using namespace formulae::general;

template <typename MList=mlist_t>
hlist_t disp(MList && ml) {
  return displayFormula(std::forward<MList>(ml));
}

template <typename MList=mlist_t>
hlist_t line(MList && ml) {
  return inlineFormual(std::forward<MList>(ml));
}

int main() {
  list_t <hlist_t> hlists;

  auto bigop = sum(optional<mlist_t >(trans("i=1")),
                   optional<mlist_t>(trans("n")));
  auto mlar = trans("(1+2)");
  auto mlop = mlist_t{bigop};


  auto mleq = mlist_t{bigop};
  transfer(mleq, trans("i="));
  transfer(mleq, mlist_t{fraction(trans("n.(n+1)"), trans("2"))});

  auto one = trans("1");
  auto two = trans("2");

  hlists.push_back(line(mlar));
//  hlists.push_back(disp(mlar));
  hlists.push_back(line(mleq));
//  hlists.push_back(disp(mleq));


  auto scr = [one, two](const std::string & s) {
    auto nuc = trans(s);
    return mlist_t{sub(nuc, one), sup(nuc, one), supsub(nuc, one, two)};
  };

  auto mlss = scr("M");
  transfer(mlss, scr("P"));
  transfer(mlss, scr("g"));
  transfer(mlss, scr("f"));
  transfer(mlss, scr("ac"));
  transfer(mlss, scr("ab"));

  using OptML = optional<mlist_t>;
  auto fss = [one](std::function<NoadRef(OptML, OptML)> f) {
    optional<mlist_t> One = OptML(one);
    return mlist_t{f(One, OptML{}),/* f(OptML{}, One), f(One, One)*/};
  };
  auto mlss1 = fss(sum<OptML, OptML>);
  transfer(mlss1, fss(integral<OptML, OptML>));
  transfer(mlss1, scr("a"));
  transfer(mlss1, scr("b"));
  transfer(mlss1, scr("aa"));
  transfer(mlss1, scr("ab"));

  auto overmlss1 = mlist_t{overline(mlss1)};

  hlists.push_back(disp(mlss1));
//  hlists.push_back(disp(overmlss1));
//  hlists.push_back(line(mlss1));
  hlists.push_back(line(overmlss1));


  NoadRef lrBra1= LeftRight_t::create(delim_t{'('}, mlss1, delim_t{')'});
  auto res1 = disp(mlist_t{lrBra1});
  hlists.push_back(res1);


//  hlist_t mathsymb;
//  for (int i = 0; i < 128; ++i) {
//    NodeRef node;
//    std::tie(node, std::ignore) = basicChar(style_t::Display, false, family_t::EX, charCode_t{i});
//    mathsymb.push_back(node);
//
//    if ((i+1)%16 == 0) {
//      hlists.push_back(mathsymb);
//      mathsymb.clear();
//    }
//  }

  shipOut(hlists);


  return 0;
}