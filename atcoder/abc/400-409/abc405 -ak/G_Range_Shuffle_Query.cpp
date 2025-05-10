#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/ds/off_line/mo.hpp"


void before() {}

using mint = M99;
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  FOR(i, n) --a[i];
  Mo mo;
  vector<int> qsx(q);
  FOR(i, q) {
    LL(l, r, x);
    mo.add(--l, r);
    qsx[i] = --x;
  }
  vector<int> c(n);
  ll B = std::ceil(std::sqrt(n));
  vector<mint> v(ceil(n, B), 1);
  vector<int> sz(ceil(n, B));
  meion add = [&](int i) -> void {
    int x = a[i];
    v[x / B] *= ++c[x];
    ++sz[x / B];
  };
  meion rm = [&](int i) -> void {
    int x = a[i];
    v[x / B] *= inv<mint>(c[x]--);
    --sz[x / B];
  };
  vector<mint> ans(q);
  meion keisan = [&](int i) -> void {
    meion R = qsx[i];
    mint div = 1;
    int s = 0;
    FOR(i, R / B) {
      div *= v[i];
      s += sz[i];
    }
    FOR(i, R / B * B, R) {
      div *= fact<mint>(c[i]);
      s += c[i];
    }
    ans[i] = fact<mint>(s) / div;
  };
  mo.calc(add, add, rm, rm, keisan);
  FOR(i, q) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"