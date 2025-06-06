#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  VEC(ll, b, n);
  ll sa = SUM(a);
  ll sb = SUM(b);
  if (n == 1) iroha UL(a[0] > b[0] ? "Mandy" : a[0] == b[0] ? "draw" : "brz");
  if (n & 1) {
    ll s = 0;
    FOR(i, n >> 1) s += a[i], s += b[i];
    if ((s + s > sa + sb) and
        (sa > sb and (s + a[n >> 1] + b[n >> 1]) * 2 > sa + sb))
      iroha UL("Mandy");
    if (s + s == sa + sb or
        (sa >= sb and (s + a[n >> 1] + b[n >> 1]) * 2 >= sa + sb))
      iroha UL("draw");
    UL("brz");
  } else {
    ll s = 0;
    FOR(i, n - 1 >> 1) s += a[n - 1 - i], s += b[n - 1 - i];
    if ((s + s > sa + sb) or
        (sb > sa and (s + a[n >> 1] + b[n >> 1]) * 2 > sa + sb))
      iroha UL("brz");
    if (s + s == sa + sb or
        (sb >= sa and (s + a[n >> 1] + b[n >> 1]) * 2 >= sa + sb))
      iroha UL("draw");
    UL("Mandy");
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"