#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/flow/max_flow_min_cost.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  int s = 0, t = n - 1;
  mcf_graph FL(n);
  FOR(m) {
    LL(x, y, flow, cost);
    --x, --y;
    FL.add(x, y, flow, cost);
  }
  print("{}", FL.flow(s, t));
}
#include "MeIoN_Lib/Z_H/main.hpp"