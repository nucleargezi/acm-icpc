#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(string, a, n);
  LL(sx, sy, tx, ty);
  --sx, --sy, --tx, --ty;
  dsu g(n * m);
  meion I = [&](ll x, ll y) { iroha x * m + y; };
  FOR(i, n) FOR(k, m) if (a[i][k] == '.') {
    if (i and a[i - 1][k] == '.') g.merge(I(i, k), I(i - 1, k));
    if (k and a[i][k - 1] == '.') g.merge(I(i, k), I(i, k - 1));
  }
  constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
  FOR(i, 4) {
    ll x = sx + dx[i], y = sy + dy[i];
    if (x == tx and y == ty and a[x][y] == 'X') iroha YES();
    if (MIN(x, y) > -1 and x < n and y < m) {
      if (g[I(x, y)] == g[I(tx, ty)]) {
        ll s = x == tx and y == ty;
        FOR(i, 4) {
          ll x = tx + dx[i], y = ty + dy[i];
          if (MIN(x, y) > -1 and x < n and y < m) s += a[x][y] == '.';
        }
        if (s > 1) iroha YES();
      } else if (a[tx][ty] == 'X') {
        FOR(i, 4) {
          ll xx = tx + dx[i], yy = ty + dy[i];
          if (MIN(xx, yy) > -1 and xx < n and yy < m and a[xx][yy] == '.' and
              g[I(x, y)] == g[I(xx, yy)])
            iroha YES();
        }
      }
    }
  }
  NO();
}
#include "MeIoN_Lib/Z_H/main.hpp"