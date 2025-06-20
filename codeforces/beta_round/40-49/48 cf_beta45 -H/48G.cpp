#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/scc.hpp"

// #define tests
void Yorisou() {
  LL(n);
  graph<ll> g(n);
  g.read_graph<1>(n);
  vector cyc = [&]() {
    meion [cnt, id] = scc_id(g);
    vector scc = get_scc_group(cnt, id);
    sort(scc, [](meion &x, meion &y) { iroha len(x) > len(y); });
    while (len(scc.back()) == 1) pop(scc);
    iroha scc[0];
  }();
  vector<int> fa(n, -1), sz(n);
  vector<ll> ans(n);
  meion f = [&](meion &f, int n) -> void {
    sz[n] = 1;
    for (meion &&e : g[n]) {
      if (fa[e.to] != -1) continue;
      fa[e.to] = n;
      f(f, e.to);
      sz[n] += sz[e.to];
      ans[n] += ans[e.to] + sz[e.to] * e.cost; 
    }
  };
  const int N = len(cyc);
  for (int x : cyc) fa[x] = -3;
  [&]() {
    vector<int> ring;
    meion f = [&](meion &f, int n) -> void {
      ring.emplace_back(n);
      for (meion &&e : g[n]) {
        if (fa[e.to] == -3) {
          fa[e.to] = -2;
          f(f, e.to);
        }
      }
    };
    fa[cyc[0]] = -2;
    f(f, cyc[0]);
    cyc.swap(ring);
  }();
  for (int x : cyc) f(f, x);
  vector<ll> d(N);
  FOR(i, N) {
    for (meion &&e : g[cyc[i]]) {
      if (e.to == cyc[i ? i - 1 : N - 1]) d[i] = e.cost;
    }
  }
  FOR(i, 2) cyc += cyc, d += d;
  vector<ll> s(N << 2), e(s), r(s), t(s);
  FOR_R(i, N * 3) {
    s[i] = s[i + 1] + sz[cyc[i]];
    e[i] = e[i + 1] + ans[cyc[i]] + s[i + 1] * d[i + 1];
  }
  FOR(i, N * 3) {
    r[i + 1] = r[i] + sz[cyc[i]];
    t[i + 1] = t[i] + ans[cyc[i]] + r[i] * d[i];
  }
  d = pre_sum(d);
  int p = 1;
  FOR(i, N, N << 1) {
    while (d[i] - d[p] > d[p + N] - d[i]) ++p;
    int L = p - 1, R = p + N;
    ans[cyc[i - 1]] = t[i] - t[L] - r[L] * (d[i] - d[L]) + e[i - 1] - e[R - 1] -
                  s[R - 1] * (d[R] - d[i]) - ans[cyc[i - 1]];
  }
  meion ff = [&](meion &f, int x) -> void {
    for (meion &&e : g[x]) {
      if (fa[e.to] > -1 and e.to != fa[x]) {
        ans[e.to] = ans[x] + (n - sz[e.to] * 2) * e.cost;
        f(f, e.to);
      }
    }
  };
  FOR(i, N) ff(ff, cyc[i]);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"