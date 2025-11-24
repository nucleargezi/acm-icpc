#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  while (N and not a.back()) pop(a), --N;
  a.ep(0);
  vector<int> f(N);
  int mx = inf<int>, p = -1;
  FOR(i, N) {
    FOR(k, N) f[k] = max(0, a[k] - (k >= i));
    int x = 0, y = SUM(f);
    FOR(k, N) x += max(k > 0 ? f[k] - f[k - 1] : f[k], 0);
    if (chmin(mx, y * 3 + x * 2 - i)) p = i;
  }
  FOR(i, p, N) --a[i], chmax(a[i], 0);
  string s;
  FOR(i, N) {
    while (a[i]) {
      int x = i;
      while (a[x]) --a[x], ++x, s += "AR";
      s += 'A' + string(x - i, 'L') + 'A';
    }
    s += "AR";
  }
  print(s + 'A' + string(N - p, 'L') + 'A');
}
#include "YRS/Z_H/main.hpp"