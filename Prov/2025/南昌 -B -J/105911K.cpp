#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  int c[4]{};
  FOR(i, n) {
    LL(x);
    ++c[x];
  }
  int ans = inf<int>;
  FOR(i, 4) {
    int t = 0;
    FOR(x, 4) {
      t += (x - i + 4) % 4 * c[x];
    }
    t += (-i - t) % 4 + 4;
    chmin(ans, t);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"