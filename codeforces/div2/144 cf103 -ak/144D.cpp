#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/bs.hpp"

TP <TN X, TN T>
pair<vc<X>, vc<int>> dij(const vc<vc<T>> &g, int s) {
  int N = si(g);
  vc<X> d(N, inf<X>);
  vc<int> f(N, -1);
  min_heap<pair<X, int>> q;
  q.eb(d[s] = 0, s);
  while (si(q)) {
    Z [s, n] = pop(q);
    if (s > d[n]) continue;
    for (Z &&e : g[n]) {
      if (chmin(d[e], s + e.w)) f[e] = e.id, q.eb(d[e], e);
    }
  }
  return {d, f};
}

void Yorisou() {
  INT(N, M, s);
  --s;
  vc<vc<edge_id_w<int>>> g(N);
  vc<T3<int>> es(M);
  FOR(i, M) {
    INT(a, b, c);
    --a, --b;
    es[i] = {a, b, c};
    g[a].ep(b, i, c), g[b].ep(a, i, c);
  }
  Z [d, f] = dij<ll>(g, s);
  INT(x);
  int rs = count(all(d), x);
  vc<char> vis(M);
  FOR(i, N) if (i != s) vis[f[i]] = 1;
  FOR(i, M) {
    var [a, b, c] = es[i];
    int l = min(d[a], d[b]), r = max(d[a], d[b]);
    if (l >= x) continue;
    if (vis[i]) {
      if (l < x and r > x) ++rs;
    } else {
      if (l < x and r >= x) {
        rs += l + c > x;
      } else {
        if (l + r + c == x + x) ++rs;
        else if (l + r + c > x + x) rs += 2;
      }
    }
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}