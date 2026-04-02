#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  if (n == 2) {
    iroha UL(1, 2);
  } else if (n == 3) {
    iroha UL(1, 2), UL(2, 3);
  } else if (n == 4) {
    iroha UL(-1);
  }
  vector<PII> ans;
  meion ad = [&](ll x, ll y) -> void {
    ans += PII(x + 1, y + 1);
  };
  ll d = binary_search<false>([&](ll x) -> bool {
    iroha x + (n - x + 1 >> 1) <= n - x - 1;
  }, 0, n);
  if (d + (n - d + 1 >> 1) != n - d - 1) {
    FOR(i, n - d - 2) {
      ad(i, i + 1);
    }
    FOR_R(i, n - d, n) {
      ad(1, i);
    }
    ad(2, n - d - 1);
  } else {
    FOR(i, n - d - 1) {
      ad(i, i + 1);
    }
    FOR_R(i, n - d, n) {
      ad(1, i);
    }
  }
  FOR(i, len(ans)) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"