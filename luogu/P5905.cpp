#include "YRS/Z_H/MeIoN_H.hpp"
#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/johnson.hpp"

// #define tests
using GT = graph<ll, 1>;
using T = GT::cost_type;
void Yorisou() {
  INT(n, m);
  graph<ll, 1> g(n);
  g.read_graph<1>(m);
  meion dis = johnson(g);
  if (dis.empty()) iroha UL(-1);
  for (const meion &v : dis) {
    ll ans = 0;
    FOR(i, n) {
      ans += std::min(v[i], 1'000'000'000ll) * (i + 1);
    }
    UL(ans);
  }
}
#include "YRS/Z_H/main.hpp"