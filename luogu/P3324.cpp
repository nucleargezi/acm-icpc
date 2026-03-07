#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/flow/max_flow.hpp"

void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  VEC(int, b, M);
  retsu<int> vis(M, N);
  IN(vis);
  setp(10);
  print(bina_real<ld>([&](ld ti) -> bool {
    int s = N + M, t = s + 1;
    max_flow<ld> FL(t + 1, s, t);
    FOR(i, N) FL.add(s, i, a[i]);
    FOR(i, M) FL.add(i + N, t, b[i] * ti);
    FOR(i, N) FOR(k, M) if (vis[k][i]) {
      FL.add(i, k + N, inf<int>);
    }
    return FL.flow() >= SUM(a) - 1e-9l;
  }, 10000, 0));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"