#include "YRS/all.hpp"
#include "YRS/dp/monge.hpp"

ll take_photos(int N, int M, int K, vc<int> p, vc<int> c) {
  vc<int> g(M + 1, -1);
  FOR(i, N) {
    int x = p[i], y = c[i];
    if (x > y) swap(x, y);
    chmax(g[x], y);
  }
  vc<PII> a;
  FOR(i, M + 1) {
    if (g[i] != -1 and (a.empty() or a.back().se < g[i])) a.ep(i, g[i]);
  }
  N = si(a);
  Z w = [&](int l, int r) -> ll {
    ll x = a[r - 1].se - a[l].fi + 1, o = 0;
    if (l) chmax(o, a[l - 1].se - a[l].fi + 1);
    return x * x - o * o;
  };
  chmin(K, N);
  return monge_dp_k(N, K, 1ll * M * M, w);
}

#ifndef MeIoN
#include "aliens.h"
#else
int main() {
  INT(N, M, K);
  vc<int> p(N), c(N);
  FOR(i, N) IN(p[i], c[i]);
  print(take_photos(N, M, K, p, c));
  return 0;
}
#endif