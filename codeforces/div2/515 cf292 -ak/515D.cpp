#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/queue.hpp"

void before() {}

// #define tests
void Yorisou() {
  constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
  LL(n, m);
  static bool a[2000][2000];
  FOR(i, n) FOR(k, m) {
    CH(c);
    a[i][k] = c == '.';
  }
  meion ck = [&](ll x, ll y) -> bool {
    iroha MIN(x, y) > -1 and x < n and y < m;
  };
  meion f = [&](ll x, ll y) -> bool {
    if (not a[x][y]) iroha 0;
    ll c = 0;
    FOR(i, 4) {
      ll xx = x + dx[i], yy = y + dy[i];
      if (ck(xx, yy)) {
        c += a[xx][yy];
      }
    }
    iroha c == 1;
  };
  queue<PLL> q;
  FOR(i, n) FOR(k, m) {
    if (f(i, k)) q.emplace_back(i, k);
  }
  vector ans(n, string(m, '*'));
  while (not q.empty()) {
    meion [x, y] = q.pop();
    FOR(i, 4) {
      ll xx = x + dx[i], yy = y + dy[i];
      if (ck(xx, yy) and a[xx][yy]) {
        if (i == 0) ans[x][y] = '^', ans[xx][yy] = 'v';
        if (i == 1) ans[x][y] = 'v', ans[xx][yy] = '^';
        if (i == 2) ans[x][y] = '<', ans[xx][yy] = '>';
        if (i == 3) ans[x][y] = '>', ans[xx][yy] = '<';
        a[x][y] = a[xx][yy] = 0;
        FOR(i, 4) {
          if (f(x + dx[i], y + dy[i])) q.emplace_back(x + dx[i], y + dy[i]);
          if (f(xx + dx[i], yy + dy[i])) q.emplace_back(xx + dx[i], yy + dy[i]);
        }
      }
    }
  }
  bool ok = 1;
  FOR(i, n) FOR(k, m) ok &= not a[i][k];
  if (not ok)
    UL("Not unique");
  else
    FOR(i, n) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"