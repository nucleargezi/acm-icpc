#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/po/all.hpp"
#include "YRS/mod/log_table.hpp"
#include "YRS/po/convolution.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = modint<1004535809>;
void conv(vc<mint> &f, vc<mint> &g, int p) {
  f = convolution(f, g);
  FOR(i, p, len(f)) f[i - p] += f[i];
  f.resize(p);
}
void pow(vc<mint> &f, int k) {
  int sz = len(f);
  vc<mint> s(sz);
  s[0] = 1;
  for (; k; k >>= 1, conv(f, f, sz)) 
    if (k & 1) conv(s, f, sz);
  f.swap(s);
}
void Yorisou() {
  INT(N, M, x, sz);
  VEC(int, s, sz);
  vc<int> t = log_table(M);
  vc<mint> f(M - 1);
  for (int x : s) if (x) f[t[x]] = 1;
  pow(f, N);
  print(f[t[x]]);
}
#include "YRS/aa/main.hpp"