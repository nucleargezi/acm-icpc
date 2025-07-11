#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  meion f = [&](ll x, ll y) { iroha x % y + y % x; };
  ll x = 0, mx = a[0];
  vector<ll> ans;
  FOR(i, n) {
    chmax(x, f(a[i], mx));
    if (a[i] > mx) {
      if (a[i] < mx + mx) {
        x = a[i];
      } else {
        FOR(k, i + 1) chmax(x, f(a[i], a[k]));
      }
      mx = a[i];
    }
    ans += x;
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"