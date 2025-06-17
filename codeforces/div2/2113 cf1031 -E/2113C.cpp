#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, m, K);
  --K;
  VEC(string, s, n);
  int a[n + 1][m + 1]{};
  bool vis[n][m]{};
  FOR(i, n) FOR(k, m) {
    if (s[i][k] == '#')
      vis[i][k] = 1;
    else if (s[i][k] == 'g')
      a[i + 1][k + 1] = 1, vis[i][k] = 1;
  }
  FOR(i, 1, n + 1) FOR(k, 1, m + 1) {
    a[i][k] += a[i][k - 1];
  }
  FOR(k, 1, m + 1) FOR(i, 1, n + 1) {
    a[i][k] += a[i - 1][k];
  }
  
  ll ans = 0, sm = a[n][m];
  FOR(i, 1, n + 1) FOR(k, 1, m + 1) {
    if (vis[i - 1][k - 1]) continue;
    ll x = i - K - 1, xx = i + K;
    ll y = k - K - 1, yy = k + K;
    chmax(x, 0), chmax(y, 0);
    chmin(xx, n), chmin(yy, m);
    chmax(ans, sm - (a[xx][yy] + a[x][y] - a[x][yy] - a[xx][y]));
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"