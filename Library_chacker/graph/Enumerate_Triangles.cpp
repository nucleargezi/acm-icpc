#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/enumerate_cyc3.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  INT(n, m);
  VEC(mint, a, n);
  graph g(n);
  g.read_graph<0, 0>(m);
  mint ans;
  enumerate_cyc_3(g, [&](int i, int k, int j) -> void {
    ans += a[i] * a[k] * a[j];
  });
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"