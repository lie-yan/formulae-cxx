#include <cstdint>
#include "OutHigh.h"
#include "Out.h"
#include "Powers2.h"
namespace formulae {
namespace dvi {

constexpr int byteSmall(int x) {
  return x & 0xff;
}

constexpr int byteChar(int x) {
  return byteSmall(x);
}

void outNat1(int x) {
  outByte(byteSmall(x));
}

void outChar(char c) {
  outByte(byteChar(c));
}

void outStr(const std::string &str) {
  for (const auto x : str)
    outChar(x);
}

void outString(const std::string &str) {
  outNat1(str.size());
  outStr(str);
}

void outZero(int n) {
  if (n == 0)
    return;
  else {
    outNat1(0);
    outZero(n - 1);
  }
}

void outNat2(int x) {
  outNat1(x >> 8);
  outNat1(x & 0xff);
}

void outNat3(int x) {
  outNat1(x >> 16);
  outNat2(x & 0xffff);
}

void outInt4(int x) {
  outNat1(x >> 24);
  outNat3(x & 0xffffff);
}

int makeNat(int twoI, int n) {
  if (n >= 0)
    return n;
  else
    return n + twoI;
}

void outInstrV(int code, int n) {
  using namespace Powers2;
  auto Code = [code](auto ell) { outNat1(code + ell); };
  if (abs(n) >= two23) {
    Code(4);
    outInt4(n);
  } else if (abs(n) >= two15) {
    Code(3);
    outNat3(makeNat(two24, n));
  } else if (abs(n) >= two7) {
    Code(2);
    outNat2(makeNat(two16, n));
  } else if (n != 0) {
    Code(1);
    outNat1(makeNat(two8, n));
  } else {
    // nop
  }
}

}
}