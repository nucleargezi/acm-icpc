#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/flow/max_flow_min_cost.hpp"

// #define tests
using RE = long double;
void Yorisou() {
  INT(m, n);
  VVEC(ll, c, n, m);
  const int N = n + n * m + 2, S = N - 2, T = N - 1;
  mcf_graph<ll> FL(N);
  FOR(i, n) FL.add(S, i, 1, 0);
  FOR(i, n) FOR(k, m) FOR(t, n) {
    FL.add(i, n + k * n + t, 1, c[i][k] * (t + 1));
  }
  FOR(k, m) FOR(t, n) {
    FL.add(n + k * n + t, T, 1, 0);
  }
  cout << fixed << setprecision(2);
  meion [fl, cost] = FL.flow(S, T);
  UL(cost / RE(n));
}
#include "YRS/Z_H/main.hpp"