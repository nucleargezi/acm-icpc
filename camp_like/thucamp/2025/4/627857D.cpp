#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  VEC(int, a, n);
  VEC(int, b, m);
  sort(a);
  vector<int> p(n);
  FOR(i, n) {
    p[i] = upper_bound(b, a[i]) - 1 + (n - i - 1);
    chmin(p[i], m - 1);
  }
  FOR_R(i, n - 1) chmin(p[i], p[i + 1]);
  ll ans = 0;
  FOR(i, m) {
    if (b[i] > a[n - 1]) break;
    int r = binary_search([&](int k) -> bool {
      iroha p[n - (k - i + 1)] >= k;
    }, i, std::min(i + n, m));
    ans += r - i + 1;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"