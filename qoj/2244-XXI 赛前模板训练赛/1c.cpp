#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/two_sat.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  TwoSat g(n);
  FOR(m) {
    LL(x, a, y, b);
    --x, --y;
    g.either(x, y, a, b);
  }
  if (g.solve()) {
    Yes();
    vector<int> ans(n);
    meion ok = g.answer();
    FOR(i, n) ans[i] = ok[i];
    print("{}", ans);
  } else {
    No();
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"