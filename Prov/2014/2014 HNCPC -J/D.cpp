#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow_min_cost.hpp"

// #define tests
void Yorisou() {
  int t = 0;
  int n, m;
  while (std::cin >> n >> m) {
    mcf_graph FL(n + 1);
    FOR(m) {
      LL(x, y, a, b);
      FL.add(x, y, 1, a);
      FL.add(x, y, 1, a + b);
    }
    FL.add(0, 1, 2, 0);
    UL(std::format("Case {}: {}", ++t, FL.flow(0, n).second));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"