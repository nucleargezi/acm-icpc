#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/online_range_q/range_lis_query.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  FOR(i, n) --a[i];
  vector<int> b(n);
  FOR(i, n) b[i] = n - 1 - a[i];
  range_lis_quis aa(a), bb(b);
  ll ans = 0;
  ll r = 0;
  meion f = [&](int l, int r) {
    iroha aa.prod(l, r) + bb.prod(l, r) == r - l + 1;
  };
  FOR(l, n) {
    while (r < n and f(l, r + 1)) ++r;
    ans += r - l;
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"