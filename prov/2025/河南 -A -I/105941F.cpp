#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  bool a[n][m]{}, vis[n][m]{};
  int dis[n][m]{};
  FOR(i, n) FOR(k, m) {
    CH(c);
    a[i][k] = c == '.';
  }
  queue<PII> q;
  q.emplace_back(0, 0);
  constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
  vis[0][0] = 1;
  vector<PII> g;
  while (not q.empty()) {
    meion [x, y] = q.pop();
    FOR(i, 4) {
      int xx = x + dx[i], yy = y + dy[i];
      if (MIN(xx, yy) > -1 and xx < n and yy < m and not vis[xx][yy] and a[xx][yy]) {
        vis[xx][yy] = 1;
        dis[xx][yy] = dis[x][y] + 1;
        q.emplace_back(xx, yy);
      }
    }
    g.emplace_back(x, y);
  }
  if (vis[n - 1][m - 1]) iroha UL(0);

  q.emplace_back(n - 1, m - 1);
  vis[n - 1][m - 1] = 1;
  vector<PII> t;
  while (not q.empty()) {
    meion [x, y] = q.pop();
    FOR(i, 4) {
      int xx = x + dx[i], yy = y + dy[i];
      if (MIN(xx, yy) > -1 and xx < n and yy < m and not vis[xx][yy] and a[xx][yy]) {
        vis[xx][yy] = 1;
        dis[xx][yy] = dis[x][y] + 1;
        q.emplace_back(xx, yy);
      }
    }
    t.emplace_back(x, y);
  }
  
  memset(vis, 0, sizeof vis);
  for (meion [x, y] : g) {
    q.emplace_back(x, y);
    vis[x][y] = 1;
    dis[x][y] = 0;
  }
  while (not q.empty()) {
    meion [x, y] = q.pop();
    FOR(i, 4) {
      int xx = x + dx[i], yy = y + dy[i];
      if (MIN(xx, yy) > -1 and xx < n and yy < m and not vis[xx][yy]) {
        vis[xx][yy] = 1;
        dis[xx][yy] = dis[x][y] + 1;
        q.emplace_back(xx, yy);
      }
    }
  }
  ll ans = inf<ll>;
  for (meion [x, y] : t) {
    chmin(ans, dis[x][y]);
  }
  UL(ans - 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"