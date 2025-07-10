#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

// #define tests
void Yorisou() {
  LL(n, m, K);
  map<PII, int> M;
  vector<PLL> ps;
  FOR(i, K) {
    LL(x, y);
    ps.emplace_back(x, y);
    M[{x, y}] = i;
  }
  dsu g(K + 4);
  static constexpr int dx[]{-1, -1, -1, 0, 0, 1, 1, 1}, 
                       dy[]{-1, 0, 1, -1, 1, -1, 0, 1};
  FOR(i, K) {
    meion [x, y] = ps[i];
    FOR(d, 8) {
      int xx = x + dx[d], yy = y + dy[d];
      if (not(xx > 0 and xx <= n and yy > 0 and yy <= m)) continue;
      if (M.contains({xx, yy})) {
        g.merge(i + 4, M[{xx, yy}] + 4);
      }
    }
    if (x == 1) g.merge(i + 4, 0);
    if (x == n) g.merge(i + 4, 1);
    if (y == 1) g.merge(i + 4, 2);
    if (y == m) g.merge(i + 4, 3);
  }
  No(g[0] == g[1] or g[2] == g[3] or g[0] == g[2] or g[1] == g[3]);
}
#include "MeIoN_Lib/Z_H/main.hpp"