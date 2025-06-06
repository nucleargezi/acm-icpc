#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"
#include "MeIoN_Lib/ds/heap/erase_heap.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  graph g(n);
  FOR(i, 1, n) {
    LL(fa);
    --fa;
    g.add(fa, i);
  }
  g.build();
  tree v(g);
  
  constexpr int N = 1'000'010;
  vector q(N, max_erase_heap<PII>{});
  FOR(i, N) q[i].emplace(-1, -1);
  vector fa(n, array<int, 22>{});
  meion f = [&](meion &f, int n) -> void {
    fa[n].fill(-1);
    fa[n][0] = q[a[n] + 1].top().second;
    FOR(i, 1, 22) if (fa[n][i - 1] != -1) fa[n][i] = fa[fa[n][i - 1]][i - 1];
    q[a[n]].emplace(v.deep[n], n);
    for (meion &&e : g[n]) if (e.to != v.fa[n]) {
      f(f, e.to);
    }
    q[a[n]].pop({v.deep[n], n});
  };
  f(f, 0);

  LL(Q);
  FOR(Q) {
    LL(s, t);
    --s, --t;
    int d = v.deep[s] - v.deep[t];
    int pr = s;
    FOR_R(i, 22) {
      if (fa[s][i] != -1 and v.deep[s] - v.deep[fa[s][i]] <= d) {
        d -= v.deep[s] - v.deep[fa[s][i]];
        s = fa[s][i];
      }
    }
    UL(a[s] - a[pr] + 1);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"