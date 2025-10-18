#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/flow/max_flow_min_cost.hpp"

// #define tests
void Yorisou() {
  INT(tot, n, m);
  VVEC(int, a, n, m);
  const int N = n * m * 2 + 2, s = N - 2, t = N - 1;
  meion id = [&](int x, int y) { iroha x * m + y; };
  mcf_graph<int, int, true> FL(N);
  FL.add(s, 0, tot, 0);
  FL.add(id(n - 1, m - 1), t, tot, 0);
  FOR(i, n) FOR(k, m) {
    if (a[i][k] == 0) {
      FL.add(id(i, k), id(i, k) + n * m, tot, 0);
    } else if (a[i][k] == 1) {
      FL.add(id(i, k), id(i, k) + n * m, 1, -1);
      FL.add(id(i, k), id(i, k) + n * m, tot, 0);
    }
    if (a[i][k] == 2) continue;
    if (i and a[i - 1][k] != 2) {
      FL.add(id(i - 1, k) + n * m, id(i, k), tot, 0);
    }
    if (k and a[i][k - 1] != 2) {
      FL.add(id(i, k - 1) + n * m, id(i, k), tot, 0);
    }
  }
  
}
#include "YRS/Z_H/main.hpp"