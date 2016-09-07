/**
 * Last modified: Tue Aug 30 16:29:05 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */

#pragma once

#include <gsl.h>
#include <iostream>

namespace grund {

template<int TypeTag, typename ValueType>
class Unit {
public:
  using intrinsic_type = ValueType;

  Unit() = default;
  Unit(const Unit &rhs) = default;
  Unit(Unit &&rhs) = default;
  Unit &operator=(const Unit &rhs) = default;
  Unit &operator=(Unit &&rhs)      = default;

  constexpr explicit Unit(const ValueType &v) : _value(v) {}
  constexpr explicit operator ValueType() const { return _value; }
  constexpr ValueType value() const { return _value; }

  // unary minus
  constexpr Unit operator-() const { return Unit(-_value); }

  constexpr Unit &operator+=(const Unit &rhs) {
    _value += rhs._value;
    return *this;
  }

  constexpr Unit operator+(const Unit &rhs) const {
    Unit ret(*this);
    return ret += rhs;
  }

  constexpr Unit &operator-=(const Unit &rhs) {
    _value -= rhs._value;
    return *this;
  }

  constexpr Unit operator-(const Unit &rhs) const {
    Unit ret(*this);
    return ret -= rhs;
  }

  constexpr bool operator==(const Unit &rhs) const {
    return _value == rhs._value;
  }

  // derived operator
  constexpr bool operator!=(const Unit &rhs) const {
    return not(*this == rhs);
  }

  constexpr bool operator<(const Unit &rhs) const {
    return _value < rhs._value;
  }

  // derived operator
  constexpr bool operator<=(const Unit &rhs) const {
    return not(rhs < *this);
  }
  // derived operator
  constexpr bool operator>(const Unit &rhs) const { return rhs < *this; }
  // derived operator
  constexpr bool operator>=(const Unit &rhs) const {
    return not(*this < rhs);
  }

  friend std::ostream &operator<<(std::ostream &out, const Unit &m) {
    out << ValueType(m);
    return out;
  }

  template<typename T>
  friend constexpr Unit operator*(const Unit &u, const T &v) {
    return Unit{u.value() * v};
  }

  // derived operator
  template<typename T>
  friend constexpr Unit operator*(const T &v, const Unit &u) {
    return operator*(u, v);
  }

  template<typename T>
  friend constexpr Unit operator/(const Unit &u, const T &v) {
    return Unit{u.value() / v};
  }


  template <typename U>
  U to() const { return U(_value); }

private:
  ValueType _value;
};
}
