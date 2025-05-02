#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  vector<ll> ans(n);
  vector c = pre_sum(a);
  FOR(i, 1, n) chmax(a[i], a[i - 1]);
  FOR(i, n) {
    ans[i] = c[n] - c[n - i] + a[n - i - 1];
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"