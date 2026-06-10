#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"

void Yorisou() {
  INT(N, M, K);
  vc<char> vis(N);
  FOR(K) {
    INT(x);
    --x;
    vis[x] = 1;
  }
  vc<T3<int>> e, ee;
  FOR(M) {
    INT(a, b, w);
    --a, --b;
    if (vis[a] or vis[b]) ee.ep(w, a, b);
    else e.ep(w, a ,b);
  }
  sort(e);
  sort(ee);

  dsu g(N);
  ll s = 0;
  if (N == 2) {
    for (var [w, a, b] : e) if (g.merge(a, b)) s += w;
    for (var [w, a, b] : ee) if (g.merge(a, b)) s += w;
  } else {
    for (var [w, a, b] : e) if (g.merge(a, b)) s += w;
    vc<char> de(N);
    for (var [w, a, b] : ee) {
      if (de[a] or de[b] or (vis[a] and vis[b])) continue;
      if (g.merge(a, b)) s += w;
      de[a] = vis[a];
      de[b] = vis[b];
    }
  }
  print(g.c == 1 ? s : -1);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}