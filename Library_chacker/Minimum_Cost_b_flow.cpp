#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/min_cost_flow_lower.hpp"

// #define tests
void Yorisou() {
  INT(n, m);
  min_cost_flow<ll, ll> FL(n);
  FOR(i, n) {
    LL(x);
    FL.add_source(i, x);
  }
  FOR(i, m) {
    LL(f, t, l, r, c);
    FL.add(f, t, l, r, c);
  }
  meion [ok, cost] = FL.solve();
  if (not ok) iroha UL("infeasible");
  UL(cost);
  for (meion &&p : FL.get_potential()) UL(p);
  for (meion &&e : FL.get_edges()) UL(e.flow());
}
#include "MeIoN_Lib/Z_H/main.hpp"