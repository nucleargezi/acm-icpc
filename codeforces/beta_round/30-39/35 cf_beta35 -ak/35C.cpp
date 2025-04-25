#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/file_io.hpp"
#include "MeIoN_Lib/ds/queue.hpp"

void before() {
#ifdef ONLINE_JUDGE
  FR("input.txt");
  FW("output.txt");
#endif
}

// #define tests
void Yorisou() {
  LL(n, m, k);
  bool vis[n][m]{};
  queue<PII> q;
  FOR(k) {
    LL(x, y);
    vis[--x][--y] = 1;
    q.emplace_back(x, y);
  }
  meion f = [&](ll x, ll y) { iroha MIN(x, y) > -1 and x < n and y < m; };
  constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
  ll x, y;
  while (not q.empty()) {
    std::tie(x, y) = pop(q);
    FOR(i, 4) {
      ll xx = x + dx[i], yy = y + dy[i];
      if (not f(xx, yy) or vis[xx][yy]) continue;
      vis[xx][yy] = 1;
      q.emplace_back(xx, yy);
    }
  }
  UL(x + 1, y + 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"