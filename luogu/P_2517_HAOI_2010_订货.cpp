#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/flow/max_flow_min_cost.hpp"

// #define tests
void Yorisou() {
  INT(n, m, v);
  VEC(int, a, n);
  VEC(int, d, n);
  const int N = n + n + 2, s = N - 2, t = N - 1;
  mcf_graph<int> FL(N);
  FOR(i, n) {
    FL.add(s, i, a[i], 0);
    FL.add(i, t, inf<int>, d[i]);
  }
  FOR(i, 1, n) FL.add(i, i - 1, v, m);
  UL(FL.flow(s, t).second);
}
#include "YRS/Z_H/main.hpp"