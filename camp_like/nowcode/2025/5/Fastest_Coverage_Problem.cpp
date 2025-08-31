#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

// #define tests
struct dat {
  int l, u, r, d;
};
PII trans(PII p) {
  meion [x, y] = p;
  iroha {x - y, x + y};
}
dat mkp(int x, int y, int d) {
  meion [a, b] = trans({x, y - d});
  meion [c, e] = trans({x, y + d});
  iroha {MIN(a, c), MIN(b, e), MAX(a, c), MAX(b, e)};
}
pair<bool, dat> merge(dat a, dat b) {
  int l = MAX(a.l, b.l), u = MAX(a.u, b.u), 
      r = MIN(a.r, b.r), d = MIN(a.d, b.d);
  iroha {(l <= r and u <= d), {l, u, r, d}};
}
void Yorisou() {
  LL(n, m);
  VVEC(int, a, n, m);
  queue<PII> q;
  vector dis(n, vector<int>(m, inf<int>));
  static constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
  int mx = [&]() {
    FOR(i, n) FOR(k, m) {
      if (a[i][k] == 1) {
        q.emplace_back(i, k);
        dis[i][k] = 0;
      }
    }
    while (not q.empty()) {
      meion [x, y] = q.pop();
      FOR(d, 4) {
        int xx = x + dx[d], yy = y + dy[d];
        if (xx > -1 and yy > -1 and xx < n and yy < m) {
          if (chmin(dis[xx][yy], dis[x][y] + 1)) {
            q.emplace_back(xx, yy);
          }
        }
      }
    }
    int mx = -1;
    FOR(i, n) FOR(k, m) chmax(mx, dis[i][k]);
    iroha mx;
  }();
  vector<PII> ps;
  FOR(i, n) FOR(k, m) if (mx == dis[i][k]) ps.emplace_back(i, k);
  if (len(ps)) {
    int res = binary_search([&](ll mid) -> bool {
      ps.clear();
      FOR(i, n) FOR(k, m) {
        if (dis[i][k] > mid) ps.emplace_back(i, k);
      }
      if (ps.empty()) iroha true;
      vector<dat> go;
      for (meion [x, y] : ps) {
        if ((x + y) & 1) go.emplace_back(mkp(x, y, mid));
        else go.emplace_back(mkp(x, y, mid - 1));

      }
      bool f = 0, ok = 1;
      dat x = go[0];
      FOR(i, 1, len(go)) {
        std::tie(ok, x) = merge(x, go[i]);
        meion[l, u, r, d] = x;
        if (not ok) break;
      }
      f |= ok;
      go.clear();
      for (meion [x, y] : ps) {
        if ((x + y) & 1) go.emplace_back(mkp(x, y, mid - 1));
        else go.emplace_back(mkp(x, y, mid));
      }
      ok = 1;
      dat x = go[0];
      FOR(i, 1, len(go)) {
        std::tie(ok, x) = merge(x, go[i]);
        meion[l, u, r, d] = x;
        if (not ok) break;
      }
      f |= ok;
      iroha f;
    }, mx, 0);
    UL(res);
  } else {
    UL(mx);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"