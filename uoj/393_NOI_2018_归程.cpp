#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"
#include "YRS/gg/sht/dij.hpp"
#include "YRS/ttr/doubling.hpp"

void Yorisou() {
  INT(N, M);
  VEC(T4<int>, es, M);
  for (Z &[x, y, w, h] : es) {
    --x, --y;
    h = -h;
    swap(x, h), swap(y, w);
  }
  sort(es);
  vc<vc<edge_w<int>>> g(N);
  for (Z &[h, w, x, y] : es) {
    g[x].ep(y, w), g[y].ep(x, w);
  }
  vc<int> dis = dij<int>(g, 0).fi;
  sh(dis, N + N - 1);

  int t = N;
  dsu f(N + N - 1);
  vc<int> hi(N + N - 1, inf<int>);
  vc<vc<int>> ng(N + N - 1);
  for (Z &[h, w, x, y] : es) {
    x = f[x], y = f[y];
    if (x != y) {
      dis[t] = min(dis[x], dis[y]);
      ng[t].ep(x), ng[t].ep(y);
      f.set(t, x), f.set(t, y);
      hi[t++] = -h;
    }
  }
  doubling db(ng, N + N - 2);

  INT(Q, K, S);
  int ls = 0, n = db.n;
  FOR(Q) {
    INT(x, h);
    x = (x + 1ll * K * ls - 1) % N;
    h = (h + 1ll * K * ls) % (S + 1);
    FOR_R(i, n) {
      int f = db.fa[x * n + i];
      if (hi[f] > h) x = f;
    }
    print(ls = dis[x]);
  }
}

int main() {
  INT(T);
  FOR(T) Yorisou();
}