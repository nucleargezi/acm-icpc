#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
using T = string;
bool cmp(const T &s, const T &t) {
  if (len(s) != len(t)) return len(s) < len(t);
  return s < t;
}
void Yorisou() {
  INT(N);
  STR(s);
  FOR(i, N) s[i] -= '0';
  vc<int> pos;
  FOR(i, N) if (s[i]) pos.ep(i);
  int sz = len(pos);
  if (not sz) return print(0);
  int re = bina([&](int m) -> bool {
    return m == 0 or N - pos[m - 1] >= m;
  }, 0, sz + 1);
  vc<int> g{sz + 1};
  if (re > 0) g.ep(re);
  if (re < sz) g.ep(re + 1);
  unique(g);
  Z gen = [&](int i) -> T {
    if (i == sz + 1) return T(sz, 1);
    int t = i - 1, st = pos[i - 1], L = N - st, M = max(L, t);
    vc<int> g;
    int c = 0;
    FOR(k, M) {
      int a = k < L ? s[N - 1 - k] : 0, b = k < t ? 1 : 0;
      g.ep((a + b + c) & 1);
      c = (a + b + c) / 2;
    }
    if (c) g.ep(1);
    while (len(g) and not g.back()) pop(g);
    T s(all(g));
    return reverse(s), s;
  };
  T ans = gen(g[0]);
  FOR(i, 1, len(g)) {
    T t = gen(g[i]);
    if (cmp(t, ans)) ans = t;
  }
  for (Z &c : ans) c += '0';
  print(ans);
}
#include "YRS/aa/main.hpp"