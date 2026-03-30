#include "YRS/all.hpp"
#include "YRS/nt/nim/nimbase.hpp"
#include "YRS/ds/seg/segl_t.hpp"

struct MX {
  struct X {
    uint x[32];
    ull s[32];
  };
  static constexpr X op(const X &a, const X &b) {
    X c{};
    FOR(i, 32) c.x[i] = a.x[i] ^ b.x[i];
    FOR(i, 32) c.s[i] = a.s[i] + b.s[i];
    return c;
  }
  static constexpr X unit() { return {}; }
  static constexpr bool commute{};
};
struct MA {
  using X = u8;
  static constexpr X op(X a, X b) { return (a + b) & u8(31); }
  static constexpr X unit() { return 0; }
  static constexpr bool commute{};
};
struct AM {
  using MX = ::MX;
  using MA = ::MA;
  using X = MX::X;
  using A = MA::X;
  static constexpr X act(X a, A f, ll) {
    rotate(bg(a.x), bg(a.x) + f, ed(a.x));
    rotate(bg(a.s), bg(a.s) + f, ed(a.s));
    return a;
  }
};
void Yorisou() {
  INT(N, Q);
  segl_t<AM> seg(N, [&](int i) -> MX::X {
    MX::X c{};
    UINT(x);
    FOR(i, 32) {
      c.x[i] = x;
      x = nim.ml(x, x);
    }
    FOR(i, 32) c.s[i] = c.x[i];
    return c;
  });
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) {
      seg.apply(l, r, 1);
    } else if (op == 2) {
      print(seg.prod(l, r).x[0]);
    } else {
      print(seg.prod(l, r).s[0]);
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"