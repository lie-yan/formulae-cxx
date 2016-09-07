/**
 * Last modified: Tue Aug 30 17:04:11 CST 2016 (outdated)
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include "unit.h"
#include <boost/optional.hpp>
#include <exception>
#include <string>
#include <vector>

namespace formulae {

template<typename T> using optional = boost::optional<T>;
template<typename T> using list_t   = std::vector<T>;

/**
 * Two main exceptions defined here.
 */
class NotImplemented: public std::logic_error {
public:
  NotImplemented(const std::string &what = "This functionality has not been implemented yet.")
      : std::logic_error(what) {}
};
class CannotHappen: public std::logic_error {
public:
  CannotHappen(const std::string &what = "Some unexpected code are executed.")
      : std::logic_error(what) {}
};

/**
 * font family and styles
 */
enum class family_t {
  RM = 0,
  MI = 1,
  SY = 2,
  EX = 3,
};

enum class style_t {
  Display      = 0,// display
  Text         = 1,// text
  Script       = 2,// script
  Scriptscript = 3,// script script
};

constexpr int famNr(family_t fam) { return static_cast<int>(fam); }
constexpr int styleNr(style_t sty) { return static_cast<int>(sty); }


/**
 * Basic types used in this project.
 */
enum class BasicTypeTag {
  charCode = 83764,
  delim,
  penalty,
  dist,
  size,
  real,
};

using charCode_t = grund::Unit<int(BasicTypeTag::charCode), wchar_t>;
using delim_t    = grund::Unit<int(BasicTypeTag::delim),    wchar_t>;
using penalty_t  = grund::Unit<int(BasicTypeTag::penalty),  int>;
using dist_t     = grund::Unit<int(BasicTypeTag::dist),     int>;
using fsize_t    = grund::Unit<int(BasicTypeTag::size),     int>; // font size
using real_t     = grund::Unit<int(BasicTypeTag::real),     double>;

}