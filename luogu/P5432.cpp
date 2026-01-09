#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/nt/bigint/big.hpp"
#include "YRS/po/fps_inv.hpp"

#define tests 0
#define fl 0
#define DB 10
using G = bigint;
using mint = M99;
string get() {
  G a, b;
  IN(a, b);
  a /= b;
  return a.to_string();
}
void Yorisou() {
  string s = get();
  int N = len(s);
  vc<mint> f(N);
  FOR(i, N) f[i] = s[i] - '0';
  reverse(all(f));
  print(fps_inv(f));
}
#include "YRS/aa/main.hpp"