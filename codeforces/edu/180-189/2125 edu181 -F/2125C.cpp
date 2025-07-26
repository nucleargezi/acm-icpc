#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
constexpr int a[]{2, 3, 5, 7};
ll f(ll x) {
  ll res = x;
  FOR(msk, 1, 16) {
    ll y = 1, b = popcount(msk);
    FOR(i, 4) if (msk >> i & 1) {
      y *= a[i];
    }
    if (y > x) continue;
    if (b & 1) res -= x / y;
    else res += x / y;
  }
  iroha res;
}
void Yorisou() {
  LL(l, r);
  --l;
  UL(f(r) - f(l));
}
#include "MeIoN_Lib/Z_H/main.hpp"