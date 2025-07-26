#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"

// #define tests
struct mono {
  struct dat {
    int lc, l, rc, r, len, ans;
  };
  using X = dat;
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept {
    if (x.lc == -1) iroha y;
    if (y.lc == -1) iroha x;
    X ret;
    ret.len = x.len + y.len;
    ret.lc = x.lc, ret.l = x.l;
    if (x.l == x.len and x.lc == y.lc) ret.l = x.l + y.l;
    ret.rc = y.rc, ret.r = y.r;
    if (y.r == y.len and y.rc == x.rc) ret.r = y.r + x.r;
    ret.ans = std::max({x.ans, y.ans, ret.l, ret.r, (x.rc == y.lc ? x.r + y.l : 0)});
    iroha ret;
  }
  static constexpr X unit() { iroha X{-1}; }
  static constexpr X from_ele(int x) { iroha {x, 1, x, 1, 1, 1}; }
  static constexpr bool commute = true;
};
void Yorisou() {
  LL(n, q);
  S(s);
  FOR(i, n) s[i] -= 'a';
  Seg<mono> seg(n, [&](int i) { iroha mono::from_ele(s[i]); });
  FOR(q) {
    LL(op);
    if (op == 1) {
      LL(x);
      CH(c);
      --x, c -= 'a';
      seg.set(x, mono::from_ele(c));
    } else {
      LL(l, r);
      --l;
      UL(seg.prod(l, r).ans);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"