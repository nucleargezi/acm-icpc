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
  INT(N, Q);
  vc<int> x(N), y(N), w(N);
  FOR(i, N) IN(x[i], y[i], w[i]);
  retsu<int> f(1501, 1501);
  FOR(Q) {
    INT(x, y, w, h, d);
    ++w, ++h;
    x += 500, y += 500;
    f[x][y] += d;
    f[x + w][y] -= d;
    f[x][y + h] -= d;
    f[x + w][y + h] += d;
  }
  FOR(i, 1501) FOR(k, 1, 1501) f[i][k] += f[i][k - 1];
  FOR(k, 1501) FOR(i, 1, 1501) f[i][k] += f[i - 1][k];
  ll s = 0;
  FOR(i, N) s += max(0, w[i] - f[x[i] + 500][y[i] + 500]);
  print(s);
}
#include "YRS/aa/main.hpp"