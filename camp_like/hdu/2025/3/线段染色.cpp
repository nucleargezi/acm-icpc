#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_affine.hpp"
#include "MeIoN_Lib/IO/fast_io.hpp"

#define tests
using mint = M17;
using mono = a_monoid_sum_affine<mint>;
constexpr ll iv = 700000005;
void Yorisou() {
  LL(n, m);
  VEC(int, a, n);
  vector<int> v(n);
  FOR(i, m) {
    LL(l, r);
    chmax(v[--r], l);
  }
  lazy_seg<mono> seg(n + 1);
  seg.set(0, 1);
  mint ans = 1, x;
  int ls = 0;
  FOR(i, n) {
    x = ans;
    mint s;
    if (ls < v[i]) {
      s = seg.prod(ls, v[i]);
      seg.apply(ls, v[i], {0, 0});
      ls = v[i];
    }
    mint p = a[i] * iv, q = -p + 1;
    if (ls < i + 1) seg.apply(ls, i + 1, {q, 0});
    seg.apply(i + 1, {1, ans * p});
    ans -= s * q;
  }
  UL(ans.val);
}
#include "MeIoN_Lib/Z_H/main.hpp"