#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/flow/max_flow_min_cost.hpp"

// #define tests
void Yorisou() {
  INT(n, m, k);
  int s = 0, t = n - 1, flow, cost;
  mcf_graph<int> FL(n + 1);
  VEC(T4<int>, e, m);
  for (meion &[f, t, fl, _] : e) {
    --f, --t;
    FL.add(f, t, fl, 0);
  }
  flow = FL.flow(s, t).first;
  for (meion &[f, t, _, cost] : e) {
    FL.add(f, t, k, cost);
  }
  FL.add(t, t + 1, k, 0);
  ++t;
  cost = FL.flow(s, t).second;
  UL(flow, cost);
}
#include "YRS/Z_H/main.hpp"