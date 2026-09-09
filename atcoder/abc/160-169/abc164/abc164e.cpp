#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/sht/dij.hpp"

void Yorisou() {
  INT(N, M, s);
  chmin(s, 2500);
  Z id = [&](int i, int k) { return i * 2501 + k; };
  int sz = id(N - 1, 2500) + 1;
  vc<vc<edge_w<int>>> g(sz);
  FOR(M) {
    INT(f, t, x, w);
    --f, --t;
    FOR(h, x, 2501) {
      g[id(f, h)].ep(id(t, h - x), w);
      g[id(t, h)].ep(id(f, h - x), w);
    }
  }
  FOR(i, N) {
    INT(c, d);
    FOR(x, 2500) g[id(i, x)].ep(id(i, min(2500, x + c)), d);
  }
  Z dis = dij<ll>(g, id(0, s)).fi;
  vc<ll> rs(N - 1, inf<ll>);
  FOR(i, 1, N) FOR(x, 2501) chmin(rs[i - 1], dis[id(i, x)]);
  for (ll x : rs) print(x);
}

int main() { Yorisou(); }