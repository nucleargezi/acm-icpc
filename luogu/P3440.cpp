#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/flow/max_flow_min_cost.hpp"

// #define tests
void Yorisou() {
  INT(n);
  const int N = n + n + 2, s = N - 2, t = N - 1;
  mcf_graph<int> FL(N);
  FOR(i, n) FL.add(s, i, 1, 0);
  FOR(i, n) FL.add(i + n, t, 1, 0);
  FOR(i, n) {
    INT(m, l, r, K);
    --m, --l;
    FOR(k, l, r) {
      FL.add(i, n + k, 1, std::abs(m - k) * K);
    }
  }
  meion [flow, cost] = FL.flow(s, t);
  if (flow != n) iroha UL("NIE");
  UL(cost);
}
#include "YRS/Z_H/main.hpp"