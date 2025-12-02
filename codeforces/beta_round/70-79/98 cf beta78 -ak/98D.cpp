#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, v, N);
  vector<PII> g;
  Z ad = [&](int a, int b, int c) { FOR(c) g.ep(a, b); };
  Z f = [&](Z &f, int i, int a, int b, int c, bool o) -> void {
    if (i == N) return;
    int k = i;
    while (k < N and v[i] == v[k]) ++k;
    int sz = k - i;
    if (k == N and o) 
      return ad(a, b, sz - 1), ad(a, c, 1), ad(b, c, sz - 1);
    if (k == i + 1 or not o)
      f(f, k, a, c, b, 0), ad(a, c, sz), f(f, k, b, a, c, 0);
    else
      f(f, k, a, b, c, 0), ad(a, b, sz), f(f, k, c, b, a, 0), 
      ad(b, c, sz), f(f, k, a, b, c, 1);
  };
  f(f, 0, 1, 2, 3, 1);
  print(len(g));
  for (Z [x, y] : g) print(x, y);
}
#include "YRS/Z_H/main.hpp"