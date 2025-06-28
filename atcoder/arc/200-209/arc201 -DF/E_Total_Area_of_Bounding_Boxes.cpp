#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/mod/powertable.hpp"

// #define tests
using mint = M99;
vector pw2 = power_table_1<mint>(2, 215141);
struct mono {
  using X = struct {
    int c;
    mint w;
  };
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept {
    X res;
    res.c = x.c + y.c;
    res.w = x.w + y.w * pw2[x.c];
    iroha res;
  }
  static constexpr X unit() { iroha X{0, 0}; }
  static constexpr bool commute = true;
};
void Yorisou() {
  LL(n);
  VEC(ll, y, n);
  vector ry = y;
  reverse(ry);
  vector<ll> a(n);
  FOR(i, n) a[i] = n + 1 - y[i];
  vector ra = a;
  reverse(ra);
  meion f = [&](vector<ll> &a) {
    Seg<mono> seg(n);
    mint res;
    FOR(i, n) {
      ll x = a[i];
      ll c = seg.prod(0, x - 1).c;
      mint vr = seg.prod(x, n).w;
      res += ((pw2[c] - 1) * x + pw2[c] * vr) * (i + 1);
      seg.set(x - 1, {1, x});
    }
    iroha res;
  };
  mint A = f(y), B = f(ry), C = f(a), D = f(ra);
  mint s;
  FOR(i, n) s += (pw2[i] - 1) * (i + 1);
  mint ans = A - (s * (n + 1) - C) - (s * (n + 1) - B) +
             (pw2[n] - n - 1) * (n + 1) * (n + 1) - mint(n + 1) * 2 * s + D;
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"