#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/off_line/mo.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q, K);
  VEC(int, a, n);
  FOR(i, n - 1) a[i + 1] ^= a[i];
  a.insert(a.begin(), 0);
  Mo mo;
  FOR(q) {
    INT(l, r);
    mo.add(--l, ++r);
  }
  vector<ll> ans(q);
  vector<int> c(1 << 20);
  ll s = 0;
  meion ad = [&](int i) -> void {
    s += c[a[i] ^ K];
    ++c[a[i]];
  };
  meion rm = [&](int i) -> void {
    --c[a[i]];
    s -= c[a[i] ^ K];
  };
  meion keisan = [&](int i) -> void {
    ans[i] = s;
  };
  mo.keisan(ad, ad, rm, rm, keisan);
  FOR(i, q) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"