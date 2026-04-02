#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/Z_H/FH.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"

// #define tests
void Yorisou() {
  LL(n, K);
  VEC(ll, a, n);
  sort(a);
  ll s = binary_search([&](ll x) -> bool {
    if (x == -1) iroha 1;
    ll s = 0;
    FOR(i, n){
      int l = lower_bound(a, a[i] - x);
      s += i - l;
      if (s >= K) iroha false;
    }
    iroha s < K;
  }, -1, 1'000'000'01);
  ll sm = 0, ans = 0;
  vector c = pre_sum(a);
  if (~s) FOR(i, n) {
      int l = lower_bound(a, a[i] - s);
      sm += i - l;
      ans += (i - l) * a[i] - (c[i] - c[l]);
    }
  UL(ans + (K - sm) * (s + 1));
}
#include "MeIoN_Lib/Z_H/main.hpp"