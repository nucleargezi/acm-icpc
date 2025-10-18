#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/k_shortest/k_shortest_path.hpp"
void before() {}

// #define tests
void Yorisou() {
  LL(n, m, k, s, t);
  graph<ll, 1> g(n);
  g.read_graph<1>(m);
  meion paths = k_shortest_path<ll>(g, --s, --t, (k << 1) + 5000);
  if (len(paths) < k) iroha No();
  sort(paths);
  meion &[cost, ps, es] = paths[--k];
  string ans;
  FOR(i, len(ps)) {
    ans += to_str(ps[i] + 1);
    ans += '-';
  }
  pop(ans);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"