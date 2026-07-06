#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/random/rng.hpp"
#include "YRS/ds/un/dsu.hpp"
#include "YRS/gg/bs.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<edge_id_w<int>>> g(N + 1);
  dsu uf(N);
  bool ok = 1;
  vc<T3<int>> es(M);
  FOR(i, M) {
    INT(a, b, w);
    --a, --b;
    es[i] = {a, b, w};
    ok &= uf.merge(a, b);
    g[a].ep(b, w, i);
    g[b].ep(a, w, i);
  }
  if (ok) return print(0);

  vc<ll> dis(N + 1, -1);
  dis[N] = 0;
  vc<int> fa[22], fe(N + 1, -1);
  FOR(i, 22) fa[i].resize(N + 1);
  fa[0][N] = N;
  FOR(i, N) if (uf[i] == i) g[N].ep(i, 0, M++);
  vc<int> d(N);
  Z gds = [&](Z &gds, int n) -> void {
    for (Z &&e : g[n]) if (dis[e] == -1) {
      fa[0][e] = n;
      fe[e] = e.id;
      dis[e] = dis[n] + e.w;
      d[e] = d[n] + 1;
      if (n != N) g[e].erase(find_if(all(g[e]), [&](var t) { return t.id == e.id; }));
      gds(gds, e);
    }
  };
  gds(gds, N);

  FOR(k, 1, 22) FOR(i, N + 1) {
    fa[k][i] = fa[k - 1][fa[k - 1][i]];
  }
  Z lca = [&](int a, int b) -> int {
    if (d[a] < d[b]) swap(a, b);
    int z = d[a] - d[b];
    FOR(i, 22) if (z >> i & 1) a = fa[i][a];
    if (a == b) return a;
    FOR_R(i, 22) {
      if (fa[i][a] != fa[i][b]) a = fa[i][a], b = fa[i][b];
    }
    return fa[0][a];
  };

  ll rs = 0;
  Z ins = [&](ll x) { rs = gcd(rs, x); };

  vc<pair<ll, int>> ri;
  vc<int> V;
  Z f = [&](Z &f, int n) -> void {
    V.ep(n);
    for (var e : g[n]) {
      if (fe[e] == e.id) {
        f(f, e);
      } else {
        ll ds = dis[e] + dis[n] - 2 * dis[lca(e, n)] + e.w;
        ins(ds);
        ri.ep(ds, e.id);
      }
    }
  };
  f(f, N);

  vc<ull> dp(N);
  set<ull> se{0};
  for (unique(ri); var [_, i] : ri) {
    var [a, b, w] = es[i];
    ull g = rng_64();
    se.eb(g);
    dp[a] ^= g, dp[b] ^= g;
  }
  
  map<ull, ll> mp;
  reverse(V);
  pop(V);
  for (int x : V) {
    int f = fa[0][x];
    if (f == N) continue;
    mp[dp[x]] += get<2>(es[fe[x]]);
    dp[f] ^= dp[x];
  }
  for (var [h, x] : mp) if (not se.contains(h)) ins(x << 1);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}