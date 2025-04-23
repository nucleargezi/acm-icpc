#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(PLL, a, n);
  vector<ll> s;
  string ans;
  FOR(i, n) {
    meion &[l, r] = a[i];
    ans += '(';
    s += i;
    l += len(ans);
    r += len(ans);
    while (not s.empty() and len(ans) + 1 >= a[s.back()].first) {
      if (len(ans) + 1 > a[s.back()].second) iroha IMPOSSIBLE();
      ans += ')';
      s.pop_back();
    }
  }
  if (not s.empty()) iroha IMPOSSIBLE();
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"