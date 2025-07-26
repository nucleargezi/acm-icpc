#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/Apck/enumerate_cyc3.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  INT(n, m);
  graph g(n);
  VEC(ll, a, n);
  g.read_graph<false, 0>(m);
  mint ans;
  enumerate_cyc_3(g, [&](int i, int k, int j) -> void {
    ans += (mint)a[i] * a[k] * a[j];
  });
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"