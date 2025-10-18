#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, d);
  VVEC(ll, a, n, d);
  int ans = -inf<int>;
  FOR(msk, 1 << d - 1) {
    int x = -inf<int>, y = -x;
    FOR(i, n) {
      int s = 0;
      FOR(k, d) {
        s += (msk >> k & 1) ? a[i][k] : -a[i][k];
      }
      chmax(x, s), chmin(y, s);
    }
    chmax(ans, x - y);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"