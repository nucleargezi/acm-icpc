#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/off_line/mo.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  meion f = a;
  unique(f);
  FOR(i, n) a[i] = lower_bound(f, a[i]);
  Mo mo;
  vector<int> qs;
  const int N = len(f);
  FOR(q) {
    LL(l, r, x);
    qs += std::ranges::binary_search(f, x) ? lower_bound(f, x) : N;
    mo.add(l, r);
  }
  vector<ll> c(N + 1), ans(q);
  meion ad = [&](int i) {
    ++c[a[i]];
  };
  meion rm = [&](int i) {
    --c[a[i]];
  };
  meion keis = [&](int i) {
    ans[i] = c[qs[i]];
  };
  mo.keisan(ad, ad, rm, rm, keis);
  FOR(i, q) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"