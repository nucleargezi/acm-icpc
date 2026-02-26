#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  retsu<char> a(N, M);
  IN(a);
  FOR(i, N) FOR(k, M) a[i][k] = a[i][k] == '.';
  ll s = 0;
  FOR(i, N) FOR(k, M) s += a[i][k];
  bool ok = 0;
  constexpr int dx[]{1, 0, -1, 0}, dy[]{0, 1, 0, -1};
  int sx, sy, sd;
  retsu<u8> v(N, M);
  Z ck = [&](int x, int y) -> bool {
    if (x < 0 or y < 0 or x >= N or y >= M) return 0;
    if (a[x][y] == 0) return 0;
    return 1;
  };
  Z f = [&](Z &f, int x, int y, int d) -> void {
    if (ok or d - sd > 5) return;
    if (v[x][y]) {
      if (x == sx and y == sy and s == 0) ok = 1;
      return;
    }
    v[x][y] = 1;
    --s;
    FOR(i, 2) {
      int rd = (d + i) % 4, xx = x + dx[rd], yy = y + dy[rd];
      if (ck(xx, yy)) {
        f(f, xx, yy, d + i);
        if (not v[xx][yy]) break;
      }
    }
    v[x][y] = 0;
    ++s;
  };
  FOR(i, N) FOR(k, M) FOR(d, 4) if (not ok and a[i][k]) {
    sx = i, sy = k, sd = d;
    f(f, i, k, d);
  }
  YES(ok);
}
#include "YRS/aa/main.hpp"