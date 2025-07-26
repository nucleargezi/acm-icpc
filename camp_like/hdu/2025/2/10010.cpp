#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"

#define tests
struct dat {
  int sz, l, r, c, f, s, e;
  int keis() {
    if (not c) iroha 0;
    if (c == 1) iroha r;
    if (e == r + 1) iroha s + (s - e + 1 << 1);
    iroha r;
  }
};
struct mono {
  using X = dat;
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept {
    if (x.sz == -1) iroha y;
    if (y.sz == -1) iroha x;
    X res{0, 0, 0, 0, 0, -1, -1};
    res.sz = x.sz + y.sz;
    res.l = x.l, res.r = y.r;
    if (x.sz == x.l) res.l = x.sz + y.l;
    if (y.sz == y.r) res.r = y.sz + x.r;
    res.c = x.c + y.c;
    if (res.c < 2) {
      iroha res;
    }
    if (y.f) {
      res.f = 1, res.s = y.s, res.e = y.e;
      iroha res;
    }
    int m = x.r + y.l;
    if (not x.c) {
      res.f = y.f;
      res.s = y.s;
      res.e = y.e;
    } else if (not y.c) {
      res.f = x.f;
      res.s = x.s;
      res.e = x.e;
    } else if (x.c == 1 and y.c == 1) {
      res.f = 0;
      res.s = res.e = m;
    } else if (x.c == 1) {
      if (m == y.s + 1) {
        res.f = 0;
        res.s = m;
        res.e = y.e;
      } else {
        res.f = 1;
        res.s = y.s;
        res.e = y.e;
      }
    } else if (y.c == 1) {
      if (x.e == m + 1) {
        res.f = x.f;
        res.s = x.s;
        res.e = m;
      } else {
        res.f = 1;
        res.s = res.e = m;
      }
    } else {
      if (x.e == m + 1 and m == y.s + 1) {
        res.f = x.f;
        res.s = x.s;
        res.e = y.e;
      } else if (m == y.s + 1) {
        res.f = 1;
        res.s = m;
        res.e = y.e;
      } else {
        res.f = 1;
        res.s = y.s;
        res.e = y.e;
      }
    }
    iroha res;
  }
  static constexpr X from_ele(int x) {
    iroha {1, x == 0, x == 0, x == 1, 0, -1, -1};
  }
  static constexpr X unit() { iroha {-1, -1, -1, -1, -1, -1, -1}; }
  static constexpr bool commute = false;
};
void Yorisou() {
  LL(n, q);
  SV(s, '0');
  Seg<mono> seg(n, [&](int i) { iroha mono::from_ele(s[i]); });
  FOR(q) {
    LL(op);
    if (op == 1) {
      LL(l, r);
      --l;
      UL(seg.prod(l, r).keis());
    } else {
      LL(x);
      --x;
      s[x] ^= 1;
      seg.set(x, mono::from_ele(s[x]));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"