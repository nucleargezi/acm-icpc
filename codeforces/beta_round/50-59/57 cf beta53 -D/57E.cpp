#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/basic/queue.hpp"
#include "YRS/ds/basic/hashmap.hpp"
#include "YRS/math/mod/modint.hpp"

// #define tests
using mint = M17;
void Yorisou() {
  LL(k, n);
  meion H = [&](ull x, ull y) -> ull {
    x += inf<int> / 4;
    y += inf<int> / 4;
    iroha x << 32 | y;
  };
  hash_map<int> se, dis;
  FOR(n) {
    INT(x, y);
    se[H(x, y)];
  }
  queue<PII> q;
  dis[H(0, 0)] = 0;
  q.emplace_back(0, 0);
  vector<int> dif, c;
  int mx = 0;
  while (not q.empty()) {
    meion [x, y] = q.pop();
    int d = dis[H(x, y)];
    if (len(c) < d + 1) c.resize(d + 1, 0);
    if (len(dif) < d + 2) dif.resize(d + 2, 0);
    ++c[d];
    ++dif[d];
    --dif[d + 1];
    if (d > mx and d > 10) {
      bool f = 1;
      FOR(i, d - 5, d - 1) if (dif[i] != 28) {
        f = 0;
        break;
      }
      if (f) break;
    }
    chmax(mx, d);
    static constexpr int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2},
                         dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
    FOR(t, 8) {
      int xx = x + dx[t], yy = y + dy[t];
      if (not dis.contains(H(xx, yy)) and not se.contains(H(xx, yy))) {
        dis[H(xx, yy)] = dis[H(x, y)] + 1;
        q.emplace_back(xx, yy);
      }
    }
  }
  if (q.empty()) iroha UL(SUM(c));
  mint ans = 0;
  FOR(i, mx) if (i <= k) ans += c[i];
  if (k >= mx) {
    int d = dif[mx - 1];
    mint l = c[mx - 1] + d, r = mint(d) * (k - mx + 1) + c[mx - 1];
    ans += (l + r) * (k - mx + 1) / 2;
  }
  UL(ans);
}
#include "YRS/Z_H/main.hpp"