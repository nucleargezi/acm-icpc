#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

struct dat {
  string s;
  int op, w, sz;
};
void Yorisou() {
  INT(N);
  vc<dat> a(N);
  map<string, int> mp;
  FOR(i, N) {
    IN(a[i].s);
    STR(op);
    INT(x, y, z);
    IN(a[i].sz);
    if (op[0] == 'w') a[i].op = 0, a[i].w = x;
    if (op[0] == 'a') a[i].op = 1, a[i].w = y;
    if (op[0] == 'o') a[i].op = 2, a[i].w = z;
    mp[a[i].s] = i;
  }

  INT(M);
  vc<dat> b(M);
  FOR(i, M) {
    IN(b[i].s);
    STR(o);
    IN(b[i].w);
    if (o[0] == 'g') b[i].op = 0;
    if (o[0] == 's') b[i].op = 1;
    if (o[0] == 'p') b[i].op = 2;
    STR(p);
    b[i].sz = mp[p];
  }

  ll s = 0;
  FOR(i, N) s += a[i].sz;
  vc<int> f(N);
  vc<vc<int>> g(N);
  FOR(i, N) f[i] += a[i].w;
  if (s == M) {
    FOR(i, M) g[b[i].sz].ep(i);
    FOR(i, N) for (int x : g[i]) if (a[i].op == b[x].op) f[i] += b[x].w;
  } else {
    FOR(p, 3) {
      vc<PII> st;
      FOR(i, M) if (b[i].op == p) st.ep(b[i].w, i);
      sort(st, greater());
      FOR(i, N) if (a[i].op == p) {
        int n = min<int>(si(st), a[i].sz);
        FOR(k, n) f[i] += st[k].fi, g[i].ep(st[k].se);
      }
    }
  }
  int x = -1, y, z;
  array<int, 3> mx{-1, -1, -1};
  FOR(i, N) if (a[i].op == 0) FOR(k, N) if (a[k].op == 1) {
    FOR(j, N) if (a[j].op == 2) {
      array nx{f[i], f[k], f[j]};
      if (chmax(mx, nx)) x = i, y = k, z = j;
    }
  }
  
  vc<char> vis(M, 1);
  for (int i : {x, y, z}) for (int x : g[i]) vis[x] = 0;
  for (int i : {x, y, z}) {
    FOR(k, M) if (vis[k] and si(g[i]) < a[i].sz) vis[k] = 0, g[i].ep(k);
    vc<string> gg;
    for (int x : g[i]) gg.ep(b[x].s);
    print(a[i].s, si(gg), gg);
  }
}

int main() {
  Yorisou();
  return 0;
}