#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  vector b = a;
  FOR(i, n - 1) chmin(b[i + 1], b[i]);
  ll ans = SUM(b);
  if (n > 1) chmin(ans, a[0] + a[1]);
  ll t = -1;
  FOR(i, 1, n - 1) if (a[i] >= b[i - 1]) {
    t = i;
    chmin(ans, std::accumulate(b.begin(), b.begin() + t + 1, 0ll));
    break;
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"