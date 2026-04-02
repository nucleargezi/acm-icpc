#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  ll ans = 1 + (n > 2);
  for (ll i = 2; i * i < n + 1; ++i) {
    ll x = i;
    if (n % i == 1) {
      ++ans;
      if (i * i != n - 1) ++ans;
    }
    while (x < n + 1) {
      if (n % x) break;
      ans += (n / x) % i == 1;
      x *= i;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"