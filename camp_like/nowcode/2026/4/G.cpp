#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/preminmax_seg.hpp"
#include "YRS/ds/seg/seg_t.hpp"

struct LR {
  struct X {
    int l, r, a, b;
    X() : l(inf<int>), r(-l) {}
    X(int i, int x) : l(x), r(x), a(i), b(i) {}
  };
  static X op(const X &a, const X &b) {
    X c(a);
    if (chmin(c.l, b.l) or (c.l == b.l and c.a > b.a)) c.a = b.a;
    if (chmax(c.r, b.r) or (c.r == b.r and c.b < b.b)) c.b = b.b;
    return c;
  }
  static X unit() { return X(); }
  static constexpr bool commute = 1;
};
struct RL {
  struct X {
    int l, r, a, b;
    X() : l(-inf<int>), r(-l) {}
    X(int i, int x) : l(x), r(x), a(i), b(i) {}
  };
  static X op(const X &a, const X &b) {
    X c(a);
    if (chmax(c.l, b.l) or (c.l == b.l and c.a > b.a)) c.a = b.a;
    if (chmin(c.r, b.r) or (c.r == b.r and c.b < b.b)) c.b = b.b;
    return c;
  }
  static X unit() { return X(); }
  static constexpr bool commute = 1;
};

struct MX {
  using X = int;
  static X op(X a, X b) { return a + b; }
  static X unit() { return 0; }
  static constexpr bool commute = 1;
};

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  seg_t<LR> FL(N, [&](int i) { return LR::X(i, a[i]); });
  seg_t<RL> FR(N, [&](int i) { return RL::X(i, a[i]); });
  preminmax_seg<int, MX> SL(N, [&](int i) -> PII { return {a[i], 1}; });
  preminmax_seg<int, MX> SR(N, [&](int i) -> PII { return {a[N - i - 1], 1}; });

  Z ke = [&](int a, int b, int l, int r, bool o) -> int {
    int s = 0;
    if (a < b) {
      s += SL.prod(l, a + 1, 1 ^ o) + SR.prod(N - r, N - b, 0 ^ o);
    } else {
      s += SL.prod(l, b + 1, 0 ^ o) + SR.prod(N - r, N - a, 1 ^ o);
    }
    return s;
  };

  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i, x);
      --i;
      FL.set(i, {i, x});
      FR.set(i, {i, x});
      SL.set(i, {x, 1});
      SR.set(N - i - 1, {x, 1});
    } else {
      INT(l, r);
      --l;
      int s = 0, ls, rs;
      if (1) {
        Z [mn, mx, a, b] = FL.prod(l, r);
        chmax(s, ke(a, b, l, r, 0));
        ls = a, rs = b;
      }
      if (1) {
        Z [mn, mx, a, b] = FR.prod(l, r);
        if (a <= ls and b >= rs) s = ke(a, b, l, r, 1);
        else if (a >= ls and b <= rs) ;
        else chmax(s, ke(a, b, l, r, 1));
      }
      if (r - l == 1) s = 1;
      print(s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}