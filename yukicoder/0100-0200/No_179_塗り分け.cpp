#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/flow/BM.hpp"

void Yorisou() {
  INT(N, M);
  VEC(string, a, N);
  int s = 0, t = 0;
  retsu<int> id(N, M);
  FOR(i, N) FOR(k, M) {
    if (a[i][k] == '#') ++s, id[i][k] = t++;
  }
  if (s == 0) return NO();

  Z ck = [&](int x, int y) {
    return x >= 0 and x < N and y >= 0 and y < M and a[x][y] == '#';
  };
  FOR(x, -N, N) FOR(y, -M, M) if (x != 0 or y != 0) {
    graph g(s);
    FOR(i, N) FOR(k, M) if (a[i][k] == '#' and ck(i + x, k + y)) {
      g.add(id[i][k], id[i + x][k + y]);
    }
    g.build();
    if (2 * len(B_matching(g).matching()) == s) return YES();
  }
  NO();
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"