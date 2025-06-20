#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  S(s);
  vector<int> a(n);
  FOR(i, n) a[i] = s[i] == 'H';
  a = pre_sum(a + a);
  ll ans = inf<ll>, sm = a[n];
  FOR(i, n) {
    chmin(ans, sm - a[i + sm] + a[i]);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"