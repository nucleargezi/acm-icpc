#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/gg/bridge.hpp"

void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  VEC(PII, es, M);
  vc<vc<edge_id>> g(N);
  FOR(i, M) {
    Z &[a, b] = es[i];
    --a, --b;
    g[a].ep(b, i), g[b].ep(a, i);
  }
  Z vis(bridge(g));
  vc<int> st;
  FOR(i, M) if (not vis[i]) {
    Z &[f, t] = es[i];
    if (a[f] != a[t]) {
      vc<int> d(N, -1), q{t};
      d[t] = 0;
      FOR(l, N) {
        int n = q[l];
        for (Z &&x : g[n]) if (x.id != i and d[x] == -1) {
          d[x] = d[n] + 1, q.ep(x);
        }
      }
      FOR(k, M) if (i != k) {
        Z &[a, b] = es[k];
        if (d[a] < d[b] or (d[a] == d[b] and a < b)) swap(a, b);
      }
      swap(f, t);
      Yes();
      for (var [a, b] : es) print(a + 1, b + 1);
      return;
    }
  }
  No();
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}