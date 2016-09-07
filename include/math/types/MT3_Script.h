/**
 * Created: Wed Aug 31 19:32:40 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once
#include "MT2_Noad.h"

namespace formulae {
namespace math {

// auxiliary structure
struct script_t {
  mlist_t nucleus;
  optional <mlist_t> supOpt;
  optional <mlist_t> subOpt;
};

class Script_t: public Noad {
public:
  Script_t(const Script_t &) = default;
  Script_t(Script_t &&) = default;
  Script_t &operator=(const Script_t &) = default;
  Script_t &operator=(Script_t &&)      = default;
  virtual ~Script_t() = default;

  virtual NoadTag tag() const { return NoadTag::Script; }
  virtual kind_t kind() const {
    auto &nuc = script.nucleus;
    if (nuc.size() == 1 and nuc[0].tag() == NoadTag::MathChar)
      return nuc[0].kind();
    else
      return kind_t::Ord;
  }

  virtual gsl::owner<Script_t *> clone() const {
    return new Script_t{*this};
  }

  template<typename ScriptType = script_t>
  static NoadRef create(ScriptType &&script) {
    return NoadRef(new Script_t(std::forward<ScriptType>(script)));
  }


protected:
  template<typename ScriptType = script_t>
  Script_t(ScriptType &&script) : script{std::forward<ScriptType>(script)} {}


public:
  script_t script;
};
}
}