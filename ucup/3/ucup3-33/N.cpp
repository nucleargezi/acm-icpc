#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"

void yorisou() {
  INT(N, M);
  STR(s);
  FOR(i, N) s[i] -= '0';
  vc<vc<int>> g(N);
  FOR(M) {
    INT(f, t);
    --f, --t;
    g[f].ep(t);
    g[t].ep(f);
  }
  
  dsu f(N);
  vc<PII> q;
  vc<int> dis(N, N + 1);
  vc<char> vis(N);
  FOR(i, N) if (s[i]) dis[i] = 0, q.ep(i, 0), vis[i] = 1;
  ll al = 0;
  while (si(q)) {
    vc<PII> qq(q), me;
    while (si(qq)) {
      int n = pop(qq).fi;
      for (int x : g[n]) {
        if (f[x] == f[n]) continue;
        if (vis[x]) me.ep(n, x);
      }
    }
    sort(all(me), [&](PII a, PII b) {
      return dis[a.fi] + dis[a.se] < dis[b.fi] + dis[b.se];
    });
    for (var [x, y] : me) if (f.merge(x, y)) al += dis[x] + dis[y] + 1;
    while (si(q)) {
      Z [n, d] = pop(q);
      for (int x : g[n]) {
        if (f[x] != f[n] and not vis[x]) {
          if (chmin(dis[x], d + 1)) {
            qq.ep(x, d + 1);
            vis[x] = 1;
            f.merge(x, n);
          }
        }
      }
    }
    q.clear();
    for (var [n, d] : qq) if (d == dis[n]) q.ep(n, d);
  }
  print(al);
}

int main() {
  INT(T);
  FOR(T) yorisou();
  return 0;
}