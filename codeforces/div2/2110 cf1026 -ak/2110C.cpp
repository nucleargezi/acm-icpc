#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, d, n);
  VEC(PLL, h, n);
  ll l = 0, r = 0;
  vector<int> L(n);
  FOR(i, n) {
    if (d[i] == -1) {
      ++r;
    } else {
      l += d[i], r += d[i];
    }
    chmin(r, h[i].second);
    chmax(l, h[i].first);
    if (l > r) iroha print("-1");
    L[i] = l;
  }
  FOR_R(i, n - 1) {
    chmax(L[i], L[i + 1] - ABS(d[i + 1]));
    L[i + 1] -= L[i];
  }
  print("{}", L);
}
#include "MeIoN_Lib/Z_H/main.hpp"