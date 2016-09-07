/**
 * Last modified: Tue Aug 30 16:52:40 CST 2016
 * @author: Lie Yan
 * @email: robin.lie.yan@outlook.com
 *
 */


#pragma once

#include <algorithm>
#include <functional>
#include <numeric>

namespace formulae {
namespace general {

template<typename List, typename T>
bool contains(const List &list, const T &x) {
  return std::cend(list) != std::find(std::cbegin(list), std::cend(list), x);
}

template<typename List>
void transfer(List &to, const List &from) {
  to.insert(std::end(to), std::begin(from), std::end(from));
}

template<typename List>
void transfer(List &to, List &&from) {
  to.insert(std::end(to),
            std::make_move_iterator(from.begin()),
            std::make_move_iterator(from.end()));
}

template<typename List1, typename List2>
List1 revAppend(List1 &&xl, List2 &&yl) {
  List1 ret{std::forward<List1>(xl)};
  std::reverse(std::begin(ret), std::end(ret));
  transfer(ret, std::forward<List2>(yl));
  return ret;
}


template<typename T, typename U>
std::function<optional<U>(optional<T>)> optMap(std::function<U(T)> f) {
  return [f](auto &&x) {// x is of type `optional<T>`
    using X = decltype(x);
    return x ? optional<U>{f(*std::forward<X>(x))} : optional<U>{};
  };
}

template<typename T, typename U>
std::function<U(optional < T > )> optFold(const U &defaultVal, std::function<U(T)> f) {
  return [f, defaultVal](auto &&x) { // x is of type `optional<T>`
    using X = decltype(x);
    return x ? f(*std::forward<X>(x)) : defaultVal;
  };
}

template<typename T>
std::function< T(optional <T>)>
optVal(const T &defVal) {
  std::function<T(T)> f = [](auto &&x) { return std::forward<decltype(x)>(x); };
  return optFold(defVal, f);
}

}
}