#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/mint.hpp"
#include "YRS/nt/bigint/big.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = mint_t<1'000'000'000>;
using T = bigint;
T A(int a) {
  T s = 1;
  FOR(i, 2, a + 1) s *= i;
  return s;
}
void Yorisou() {
  LL(a, b);
  a = a / 1000 % b;
  T res = A(b) / A(a) / A(b - a);
  mint s;
  for (char x : res.to_binary_string()) {
    if (x == '0') s = s * 2;
    else s = s * 2 + 1;
  }
  print(s);
}
#include "YRS/aa/main.hpp"