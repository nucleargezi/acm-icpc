#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/Basic.hpp"

// #define tests
void yorisou(int N) {
  graph g(N);
  FOR(i, 1, N) {
    INT(fa);
    --fa;
    g.add(fa, i);
  }
  g.build();
  VEC(int, a, N);
  vector<ll> ans(N);
  ll s = 0;
  hash_map<int> c, r;
  int col = 0;
  Z f = [&](Z &f, int n, int fa) -> void {
    int x = a[n];
    int hcol = col, hc = c[x], hr = r[x], hs = s;
    s -= r[x];
    r[x] = col;
    s += r[x];
    col += not c[x]++;
    ans[n] = s;
    for (Z &&e : g[n])
      if (e.to != fa) f(f, e.to, n);
    col = hcol;
    c[x] = hc;
    r[x] = hr;
    s = hs;
  };
  f(f, 0, 0);
  FOR(i, 1, N) UL(ans[i]);
}
void Yorisou() {
  int N;
  while (IN(N)) yorisou(N);
}
#include "YRS/Z_H/main.hpp"