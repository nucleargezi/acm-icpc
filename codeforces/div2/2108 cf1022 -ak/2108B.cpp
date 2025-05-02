#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n, x);
  if (n == 1 and not x) iroha UL(-1);
  if (not x) iroha UL(n + (n & 1 ? 3 : 0));
  ll c = popcount(x);
  if (c >= n) {
    UL(x);
  } else {
    ll ans = x + n - c;
    if (n - c & 1) {
      if (c == 1) {
        ans = x + n - c - 1;
        FOR(i, 40) {
          if (x >> i & 1 ^ 1) {
            ans += 1ll << i + 1;
            break;
          }
        }
      } else {
        ans = x + n - c + 1;
      }
    }
    UL(ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"