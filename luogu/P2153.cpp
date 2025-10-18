#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/flow/max_flow_min_cost.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  const int S = 0, T = n - 1, N = n + n;
  mcf_graph<int> FL(N);
  FOR(i, 1, n - 1) {
    FL.add(i, i + n, 1, 0);
  }
  while (m--) {
    INT(x, y, w);
    --x, --y;
    if (x == S and y == T) {
      FL.add(S, T, 1, w);
    } else if (x == S) {
      FL.add(x, y, 1, w);
    } else {
      FL.add(x + n, y, 1, w);
    }
  }
  UL(FL.flow(S, T));
}
#include "YRS/Z_H/main.hpp"