#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/modint.hpp"
#include "YRS/mod/mod_sqrt.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = M17;
mint keis(int K, int c) {
  mint A = (mint(c - 2) + mod_sqrt(mint(c - 2).pow(2) + mint(4) * (c - 1)));
  mint B = (mint(c - 2) - mod_sqrt(mint(c - 2).pow(2) + mint(4) * (c - 1)));
  A *= mint(2).inv();
  B *= mint(2).inv();
  mint k2 = mint(c) * mint(c - 1) * mint(c - 2);
  mint aa = k2 / (A.pow(2) - B.pow(2));
  mint bb = -aa;
  return aa * A.pow(K - 1) + bb * B.pow(K - 1);
}
void Yorisou() {
  INT(N, K, c);
  if (c == 2) return print(K & 1 ? 0 : 2);
  mint s = keis(K, c);
  N -= 1;
  mint g = mint(c - 2) * (c - 2) + c - 1;
  g = g.pow(N);
  g = g.pow(K);
  print(s * g);
}
#include "YRS/aa/main.hpp"