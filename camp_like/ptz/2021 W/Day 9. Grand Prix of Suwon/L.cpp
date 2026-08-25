#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/sht/k_short_walk.hpp"

void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  vc<array<array<int, 2>, 2>> id(N);
  int s = 0;
  FOR(i, N) FOR(k, 2) FOR(j, 2) id[i][k][j] = s++;
  int t = s + 1;
  vc<vc<edge_w<int>>> g(t + 1);
  FOR(i, N - 1) {
    int k = i + 1;
    g[id[i][0][1]].ep(id[k][1][0], 0);
    g[id[i][0][1]].ep(id[k][1][1], a[k]);
    g[id[i][1][0]].ep(id[k][0][0], 0);
    g[id[i][1][0]].ep(id[k][0][1], a[k]);
    g[id[i][1][1]].ep(id[k][1][0], 0);
    g[id[i][1][1]].ep(id[k][1][1], a[k]);
    g[id[i][0][0]].ep(id[k][0][1], a[k]);
  }
  g[s].ep(id[0][0][1], a[0]);
  g[s].ep(id[0][0][0], 0);
  int k = N - 1;
  g[id[k][0][1]].ep(t, 0);
  g[id[k][1][0]].ep(t, 0);
  g[id[k][1][1]].ep(t, 0);
  Z rs = k_short_walk<ll>(g, s, t, K);
  FOR(i, K) print(rs[i] == inf<ll> ? -1 : rs[i]);
}

int main() { Yorisou(); }