#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n << 1);
  max_heap<ll> q;
  ll ans = 0;
  ll s = 0;
  FOR(i, n << 1) {
    q.emplace(a[i], i);
    int x = (i >> 1) + 1;
    while (s < x) {
      ll x = pop(q);
      ans += x;
      ++s;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"