#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(x, y, L);
  int xx = abs(x), yy = abs(y);
  int a = ceil(xx, L), b = ceil(yy, L);
  int ans = inf<int>;
  vc<int> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
  FOR(i, 4) {
    int s = dx[i] * xx, t = dy[i] * yy;
    if (x == s and y == t) chmin(ans, i + a * !!dx[i] + b * !!dy[i]);
  }
  swap(dx[1], dx[3]);
  FOR(i, 4) {
    int s = dx[i] * xx, t = dy[i] * yy;
    if (x == s and y == t) chmin(ans, i + a * !!dx[i] + b * !!dy[i]);
  }
  dx = {-1, -1, 1, 1}, dy = {1, -1, -1, 1};
  FOR(i, 4) {
    int s = dx[i] * xx, t = dy[i] * yy;
    if (x == s and y == t) chmin(ans, 1 + i + a * !!dx[i] + b * !!dy[i]);
  }
  dx = {1, 1, -1, -1}, dy = {1, -1, -1, 1};
  FOR(i, 4) {
    int s = dx[i] * xx, t = dy[i] * yy;
    if (x == s and y == t) chmin(ans, 1 + i + a * !!dx[i] + b * !!dy[i]);
  }
  print(ans);
}
#include "YRS/aa/main.hpp"