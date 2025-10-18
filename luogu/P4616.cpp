#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/graph/Tree/Basic.hpp"
#include "YRS/ds/dsu.hpp"

// #define tests
void Yorisou() {
  INT(N, M, Q);
  dsu g(N + N - 1);
  vector<int> dat(N - 1);
  graph G(N + N - 1);
  int t = N - 1;
  FOR_R(i, 1, M + 1) {
    FOR(k, i + i, N + 1, i) {
      int x = g[k - 1], y = g[k - i - 1];
      if (x != y) {
        ++t;
        G.add(x, t);
        G.add(y, t);
        g.set(t, x);
        g.set(t, y);
        dat[t - N] = M - i + 1;
      }
    }
  }
  G.build();
  tree v(G, t);

  FOR(Q) {
    INT(x, y);
    --x, --y;
    print(dat[v.LCA(x, y) - N]);
  }
}
#include "YRS/Z_H/main.hpp"