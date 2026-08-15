#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wblt/wblt_mono.hpp"

struct MX {
  struct X {
    int s, l, r;
  };
  static X unit() { return {}; }
  static X op(const X &a, const X &b) {
    return {a.s + b.s, min(a.l, a.s + b.l), max(b.r, a.r + b.s)};
  }
};

void Yorisou() {
  INT(Q);
  constexpr int lm = 1 << 22;
  wblt_mono<MX> g(lm);
  uint t = 0;
  FOR(Q) {
    INT(l, r);
    Z [ls, m, rs] = g.spl(t, l, r);
    Z [s, x, y] = g.prod(m);
    print(2 * (y - x));
    m = g.me(g.newnode({1, 0, 1}), m, g.newnode({-1, -1, 0}));
    t = g.me(ls, m, rs);
    if (si(g.tr) - g.fr > lm - 1000) g.gc(t);
  }
}

int main() {
  Yorisou();
  return 0;
}