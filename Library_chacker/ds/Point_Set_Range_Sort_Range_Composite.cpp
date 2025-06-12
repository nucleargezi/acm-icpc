#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/sort_seg.hpp"
#include "MeIoN_Lib/ds/monoid/affine.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
using mono = monoid_affine<mint>;
void Yorisou() {
  LL(n, q);
  VEC(T3<ll>, a, n);
  vector<int> key(n);
  vector<pair<mint, mint>> dat(n);
  for (int t = 0; meion [p, a, b] : a) {
    key[t] = p;
    dat[t] = {a, b};
    ++t;
  }
  sort_seg<mono> seg(n + q << 5, 1'000'000'001, key, dat);
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(i, p, a, b);
      seg.set(i, p, {a, b});
    } else if (op == 1) {
      LL(l, r, x);
      UL(mono::eval(seg.prod(l, r), x));
    } else if (op == 2) {
      LL(l, r);
      seg.sort_inc(l, r);
    } else {
      LL(l, r);
      seg.sort_dec(l, r);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"