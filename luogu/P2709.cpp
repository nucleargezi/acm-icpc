#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/off_line/mo.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q, k);
  VEC(ll, a, n);
  vector<ll> c(k + 1);
  Mo mo;
  FOR(q) {
    LL(l, r);
    mo.add(--l, r);
  }
  ll res = 0;
  meion ad = [&](int i) -> void {
    ll x = a[i];
    res -= c[x] * c[x];
    ++c[x];
    res += c[x] * c[x];
  };
  meion rm = [&](int i) -> void {
    ll x = a[i];
    res -= c[x] * c[x];
    --c[x];
    res += c[x] * c[x];
  };
  vector<ll> ans(q);
  meion keisan = [&](int i) -> void {
    ans[i] = res;
  };
  mo.calc(ad, ad, rm, rm, keisan);
  FOR(i, q) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"