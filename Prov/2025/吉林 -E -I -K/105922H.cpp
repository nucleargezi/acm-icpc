#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_mul.hpp"
#include "MeIoN_Lib/math/mod/modint61.hpp"

// #define tests
using mint = modint61;
void Yorisou() {
  LL(n, q);
  vector<mint> a(n);
  meion f = [&](ll x) -> mint {
    iroha mint(131).pow(x);
  };
  FOR(i, n) {
    LL(x);
    a[i] = f(x);
  }
  lazy_seg<a_monoid_sum_add<mint>> A(n + 1 >> 1, [&](int i) { iroha a[i << 1]; }),
      B(n >> 1, [&](int i) { iroha a[i << 1 | 1]; });
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(l, r, x);
      --l;
      A.apply(l + 1 >> 1, r + 1 >> 1, f(x));
      B.apply(l >> 1, r >> 1, f(x));
    } else {
      LL(l, r);
      --l;
      YES(A.prod(l + 1 >> 1, r + 1 >> 1) == B.prod(l >> 1, r >> 1));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"