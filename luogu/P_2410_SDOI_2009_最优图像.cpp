#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow_min_cost.hpp"

void before() {}

// #define tests
using RE = long double;
using MCF = mcf_graph<int, RE, true>;
void Yorisou() {
  LL(n, m);
  RE v[n][m];
  FOR(i, n) FOR(k, m) {
    LL(x);
    v[i][k] = std::log(x);
  }
  VEC(ll, x, n);
  VEC(ll, y, m);
  ll sum = SUM(x);
  int s = 0, t = n + m + n * m + 1;
  MCF FL(t + 1);
  FOR(i, n) {
    FL.add(s, i + 1, x[i], 0);
  }
  FOR(i, m) {
    FL.add(i + n + n * m + 1, t, y[i], 0);
  }
  FOR(i, n) FOR(k, m) {
    FL.add(i + 1, n + i * m + k + 1, 1, -v[i][k]);
    FL.add(n + i * m + k + 1, n + n * m + k + 1, 1, 0);
  }
  FL.flow(s, t);
  vector ans(n, string(m, '0'));
  for (meion [f, t, cap, flow, cost] : FL.edges()) {
    if (f > 0 and f < n + 1 and flow) {
      t -= n + 1;
      ++ans[t / m][t % m];
    }
  }
  FOR(i, n) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"