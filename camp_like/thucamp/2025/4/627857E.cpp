#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  VEC(ll, b, n);
  meion check = [&](ll m) -> bool {
    PLL MX = {-inf<ll>, -inf<ll>};
    FOR(i, n) if (b[i] <= m) chmax(MX, PLL{a[i], i});
    meion [mx, id] = MX;
    vector<ll> v;
    FOR(i, n) if (id != i) {
      v.emplace_back(a[i]);
    }
    sort(v);
    for (ll x : v) {
      if (x < mx) ++mx;
      else iroha false;
    }
    iroha true;
  };
  if (not check(QMAX(b))) iroha UL(-1);
  UL(binary_search(check, QMAX(b), 0));
}
#include "YRS/Z_H/main.hpp"