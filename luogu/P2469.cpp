#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/flow/max_flow_min_cost.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  VEC(int, a, n);
  const int N = n * 2 + 2, s = N - 2, t = N - 1;
  mcf_graph<int> FL(N);
  FOR(i, n) FL.add(s, i, 1, 0);
  FOR(i, n) FL.add(i + n, t, 1, 0);
  FOR(i, n) FL.add(s, i + n, 1, a[i]);
  while (m--) {
    INT(x, y, w);
    --x, --y;
    if (x > y) swap(x, y);
    FL.add(x, y + n, 1, w);
  }
  UL(FL.flow(s, t).second);
}
#include "YRS/Z_H/main.hpp"