#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  SV(s, '0');
  vector<ll> ans;
  meion f = [&](ll x) -> vector<ll> {
    if (x == 0 or x == 1) iroha {};
    if (x == 2) iroha {2};
    if (x == 3) iroha {3};
    if (x == 4) iroha {2, 2, 3};
    if (x == 5) iroha {5};
    if (x == 6) iroha {3, 5};
    if (x == 7) iroha {7};
    if (x == 8) iroha {2, 2, 2, 7};
    iroha {2, 3, 3, 7};
  };
  FOR(i, n) {
    ans += f(s[i]);
  }
  sort(ans, greater());
  string res;
  for (ll x : ans) res += x + '0';
  UL(res);
}
#include "MeIoN_Lib/Z_H/main.hpp"