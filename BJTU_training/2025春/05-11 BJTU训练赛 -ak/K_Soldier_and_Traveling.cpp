#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(ll, a, n);
  VEC(ll, b, n);
  VEC(PLL, e, m);
  if (SUM(a) != SUM(b)) iroha NO();
  int s = 0, t = n << 1 | 1;
  max_flow FL(t + 1, s, t);
  FOR(i, 1, n + 1) {
    FL.add(s, i, a[i - 1]);
    FL.add(i + n, t, b[i - 1]);
    FL.add(i, i + n, a[i - 1]);
  }
  for (meion [x, y] : e) {
    FL.add(x, y + n, a[x - 1]);
    FL.add(y, x + n, a[y - 1]);
  }
  if (FL.flow() != SUM(a)) iroha NO();
  YES();
  vector ans(n, vector<int>(n));
  for (meion [f, t, flow] : FL.get_flow_edges()) {
    if (f > 0 and f < n + 1 and t > n and t < n + n + 1) {
      ans[f - 1][t - n - 1] += flow;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"