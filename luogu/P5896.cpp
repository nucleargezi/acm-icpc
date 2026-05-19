#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/dp/monge.hpp"

void Yorisou() {
  INT(N, M, K);
  vc<int> g(M + 1, -1);
  FOR(N) {
    INT(x, y);
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
  print(monge_dp_k(N, K, 1ll * M * M, w));
}

int main() {
  Yorisou();
  return 0;
}