#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/gg/bs.hpp"

void Yorisou() {
  INT(N, M, T);
  VEC(PII, e, M);
  for (Z &[a, b] : e) --a, --b;
  vc<T3<int>> spe, noe;
  INT(K);
  vc<int> id(M, -1);
  FOR(i, K) {
    INT(ei, w);
    --ei;
    id[ei] = i;
    spe.ep(e[ei].fi, e[ei].se, w);
  }
  FOR(i, M) if (id[i] == -1) noe.ep(e[i].fi, e[i].se, T);
  vc<vc<edge_w<ll>>> g(N);
  for (var [a, b, c] : noe) {
    g[a].ep(b, c);
    g[b].ep(a, c);
  }

  retsu<ll> d(N, N, inf<ll> / 4);
  FOR(s, N) {
    vc<int> q{s};
    Z dis = d[s];
    dis[s] = 0;
    FOR(i, si(q)) {
      int n = q[i];
      ll d = dis[n];
      for (var [x, w] : g[n]) {
        if (chmin(dis[x], d + w)) q.ep(x);
      }
    }
  }

  vc<int> s;
  for (var [a, b, c] : spe) {
    s.ep(a), s.ep(b);
  }
  unique(s);
  int sz = si(s);
  vc<int> to(N);
  FOR(i, sz) to[s[i]] = i;
  vc<T3<int>> trs(spe);
  for (Z &[a, b, c] : trs) a = to[a], b = to[b];
  vc<vc<pair<int, ll>>> gg(sz);
  FOR(i, si(trs)) {
    var [a, b, c] = trs[i];
    gg[a].ep(b, i);
    gg[b].ep(a, i);
  }

  retsu<ll> dis(sz, sz, inf<ll> / 4);
  FOR(i, sz) dis[i][i] = 0;
  FOR(i, sz) FOR(k, i + 1, sz) {
    int a = s[i], b = s[k];
    chmin(dis[i][k], d[a][b]);
    chmin(dis[k][i], d[a][b]);
  }

  vc<ll> td(N, inf<ll> / 4);
  vc<char> vis(sz);
  INT(Q);
  FOR(Q) {
    INT(ei, w);
    --ei;
    int i = id[ei];
    get<2>(spe[i]) = w;
    get<2>(trs[i]) = w;
    INT(qs);
    FOR(qs) {
      INT(a, b);
      --a, --b;
      ll rs = d[a][b];
      for (int x : s) td[to[x]] = d[a][x];
      for (;;) {
        int n = -1;
        ll mx = inf<ll>;
        FOR(i, sz) if (not vis[i] and chmin(mx, td[i])) n = i;
        if (n == -1) break;
        vis[n] = 1;
        ll d = td[n];
        for (var [x, ei] : gg[n]) {
          int w = get<2>(trs[ei]);
          chmin(td[x], w + d);
        }
        FOR(i, sz) if (i != n) chmin(td[i], d + dis[n][i]);
      }

      for (int x : s) {
        int t = to[x];
        chmin(rs, td[t] + d[b][x]);
        td[t] = inf<ll> / 4, vis[t] = 0;
      }
      print(rs);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}