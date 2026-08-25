#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/scc.hpp"

void gen() {
  INT(N, M);
  VEC(PII, e, M);
  for (Z &[a, b] : e) --a, --b;
  INT(K);
  VEC(int, a, K);
  for (int &x : a) --x;

  vc<int> id(N, -1);
  FOR(i, K) id[a[i]] = i;
  vc<PII> se, ls;
  for (Z &[a, b] : e) {
    if (id[a] != -1 and id[b] != -1) {
      if (id[a] > id[b]) swap(a, b);
      if (id[a] == 0 and id[b] == K - 1) swap(a, b);
      se.ep(a, b);
    } else {
      ls.ep(a, b);
    }
  }
  vc<vc<PII>> g(N);
  int sz = si(ls);
  vc<char> vis(sz);
  FOR(i, sz) {
    var [a, b] = ls[i];
    g[a].ep(b, i);
    g[b].ep(a, i);
  }
  vc<int> d(N,-1);
  for (int x : a) d[x] = 0;

  Z f = [&](Z &f, int n, int p) -> void {
    for (Z [x, i] : g[n]) if (not vis[i]) {
      vis[i] = 1;
      if (d[x] == -1) {
        se.ep(n, x);
        d[x] = d[n] + 1;
        f(f, x, n);
      } else {
        if (d[n] < d[x] or (d[n] == d[x] and n < x)) {
          se.ep(n, x);
        } else {
          se.ep(x, n);
        }
      }
    }
  };
  for (int x : a) f(f, x, x);
  for (var [a, b] : se) print(a + 1, b + 1);
}

void slv() {
  INT(N, M);
  VEC(PII, e, M);
  for (Z &[a, b] : e) --a, --b;
  vc<vc<int>> g(N);
  for (var [a, b] : e) g[a].ep(b);
  Z [C, id] = scc(g);

  vc<vc<int>> v(C);
  FOR(i, N) v[id[i]].ep(i);
  vc<int> s;
  int ii = -1;
  FOR(i, C) if (si(v[i]) > 1) s = v[i], ii = i;
  vc<int> in(N);
  g.assign(N, {});
  vc<set<int>> gg(N);
  for (var [a, b] : e) if (id[a] == ii and id[b] == ii) {
    g[a].ep(b);
    ++in[b];
    gg[b].eb(a);
  }
  vc<int> q;
  for (int x : s) if (in[x] == 1) {
    q.ep(x);
  }
  vc<PII> ee;
  FOR(i, si(q)) {
    int n = q[i];
    vc<PII> del;
    for (int fa : gg[n]) {
      ee.ep(fa, n);
      for (int x : g[fa]) {
        --in[x];
        del.ep(x, fa);
        if (in[x] == 1) q.ep(x);
      }
    }
    for (var [x, fa] : del) gg[x].extract(fa);
  }
  
  g.assign(N, {});
  for (var [a, b] : ee) g[a].ep(b);
  q.clear();
  q.ep(ee[0].fi);
  while (si(q) < si(ee)) {
    int n = q.back();
    for (int x : g[n]) q.ep(x);
  }
  for (int &x : q) ++x;
  print(q);
}

int main() {
  INT(op);
  if (op == 1) {
    gen();
  } else {
    slv();
  }
  return 0;
}