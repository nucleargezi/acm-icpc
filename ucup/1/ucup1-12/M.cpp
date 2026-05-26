#include "YRS/all.hpp"
#include "YRS/ds/basic/queue.hpp"
#include "YRS/flow/max_flow.hpp"

struct dsu {
  using ll = short;
  vc<ll> fa;
  dsu(ll N) : fa(N, -1) {}
  ll f(ll x) {
    while (fa[x] >= 0) {
      ll p = fa[fa[x]];
      if (p < 0) return fa[x];
      x = fa[x] = p;
    }
    return x;
  }
  ll operator[](ll x) { return f(x); }
  bool merge(ll a, ll b) {
    a = f(a) ,b = f(b);
    if (a == b) return 0;
    if (fa[a] > fa[b]) swap(a, b);
    fa[a] += fa[b];
    fa[b] = a;
    return 1;
  }
};

TE pair<short, vc<short>> scc(vc<vc<T>> &g) {
  short N = si(g), t = 0, c = 0;
  vc<short> a(N), b(N), id(N), s;
  Z f = [&](Z &f, short n) -> void {
    a[n] = b[n] = ++t;
    s.ep(n);
    for (short x : g[n]) {
      if (a[x]) chmin(b[n], a[x]);
      else f(f, x), chmin(b[n], b[x]);
    }
    if (a[n] == b[n]) {
      short x = pop(s);
      for (; x != n; x = pop(s)) id[x] = c, a[x] = N;
      id[x] = c++, a[x] = N;
    }
  };
  FOR(n, N) if (not a[n]) f(f, n);
  FOR(i, N) id[i] = c - id[i] - 1;
  return {c, id};
}

TE vc<vc<short>> scc_dag(vc<vc<T>> &g, short c, const vc<short> &id) {
  vc<ull> es;
  short N = si(g);
  FOR(i, N) for (short x : g[i]) {
    if (id[i] != id[x]) es.ep(ull(id[i]) << 32 | id[x]);
  }
  unique(es);
  vc<vc<short>> ng(c);
  for (ull e : es) {
    uint f = e >> 32, t = e;
    ng[f].ep(t);
  }
  return ng;
}

Z dag_path_cover(vc<vc<short>> &v) {
  using ll = short;
  short N = si(v), s = N << 1, t = s | 1;
  max_flow<ll> FL(t + 1, s, t);
  FOR(i, N) {
    FL.add(s, i << 1 | 1, 1);
    FL.add(i << 1, t, 1);
    FL.add(i << 1, i << 1 | 1, inf<ll>);
  }
  FOR(f, N) {
    for (ll t : v[f]) FL.add(f << 1 | 1, t << 1, inf<ll>);
    v[f].clear();
    v[f].shrink_to_fit();
  }
  FL.flow();
  dsu g(N);
  for (var p : FL.path_decomposition()) {
    ll x = p[1], y = p[si(p) - 2];
    g.merge(x >> 1, y >> 1);
  }
  vc<short> ans(N, N);
  t = 0;
  FOR(i, N) if (g[i] == i) ans[i] = t++;
  FOR(i, N) if (g[i] != i) ans[i] = ans[g[i]];
  g.fa.clear();
  g.fa.shrink_to_fit();
  return ans;
}
void Yorisou() {
  using ll = short;
  LL(N, M);
  vc<vc<ll>> g(N);
  VEC(PII, es, M);
  vc<ll> in(N);
  for (Z &[a, b] : es) --a, --b, ++in[a];
  FOR(i, N) g[i].reserve(in[i]);
  for (var [a, b] : es) g[a].ep(b);
  
  Z [c, id] = scc(g);
  vc<vc<ll>> v(c);
  es.clear();
  FOR(i, N) for (ll x : g[i]) if (id[x] != id[i]) es.ep(id[i], id[x]);
  unique(es);
  es.shrink_to_fit();
  in.resize(c);
  in.shrink_to_fit();
  fill(all(in), 0);
  for (var [a, b] : es) ++in[a];
  FOR(i, c) v[i].reserve(in[i]);
  fill(all(in), 0);
  for (var [a, b] : es) v[a].ep(b), ++in[b];

  queue<ll> q(c);
  FOR(i, c) if (not in[i]) q.eb(i);
  vc<ll> V;
  V.reserve(c);
  while (si(q)) {
    ll n = pop(q);
    V.ep(n);
    for (ll x : v[n]) if (not --in[x]) q.eb(x);
  }
  in.clear();
  in.shrink_to_fit();
  q.q.clear();
  q.q.shrink_to_fit();
  vc<ll> L(c);
  FOR(i, c) L[V[i]] = i;
  FOR(i, N) g[i].clear();
  FOR(i, c, N) g[i].shrink_to_fit();
  FOR(i, c) {
    for (ll x : v[V[i]]) g[i].ep(L[x]);
    v[V[i]].clear();
    v[V[i]].shrink_to_fit();
  }
  v.clear();
  v.shrink_to_fit();
  
  Z cov = dag_path_cover(g);
  FOR(i, N) put(cov[L[id[i]]] + 1, " \n"[i + 1 == N]);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  Yorisou();
  return 0;
}