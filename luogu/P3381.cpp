#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/flow/max_flow_min_cost.hpp"

// #define tests
void Yorisou() {
  INT(n, m, s, t);
  --s, --t;
  mcf_graph<ll> FL(n);
  while (m--) {
    INT(f, t, fl, cost);
    --f, --t;
    FL.add(f, t, fl, cost);
  }
  UL(FL.flow(s, t));
}
#include "YRS/Z_H/main.hpp"