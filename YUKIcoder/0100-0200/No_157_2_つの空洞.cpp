#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/ds/un/dsu.hpp"

void Yorisou() {
  INT(M, N);
  dsu g(N * M);
  VEC(string, a, N);
  Z id = [&](int x, int y) { return x * M + y; };
  FOR(i, N) FOR(k, M) if (a[i][k] == '.') {
    if (i != 0 and a[i - 1][k] == a[i][k]) g.merge(id(i - 1, k), id(i, k));
    if (k != 0 and a[i][k - 1] == a[i][k]) g.merge(id(i, k - 1), id(i, k));
  }
  int s = inf<int>;
  FOR(i, N) FOR(k, M) if (a[i][k] == '.') {
    FOR(x, N) FOR(y, M) if (a[x][y] == '.' and g[id(i, k)] != g[id(x, y)]) {
      chmin(s, abs(x - i) + abs(y - k));
    }
  }
  print(s - 1);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"