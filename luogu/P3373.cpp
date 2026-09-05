#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"
#include "YRS/mod/barrett.hpp"

barrett m;
struct MX {
  using X = int;
  using A = PII;
  static X op(X a, X b) { return m(a + b); }
  static X unit() { return 0; }
  static A fu(const A &f, const A &g) {
    return {m.ml(f.fi, g.fi), m(m.ml(f.se, g.fi) + g.se)};
  }
  static A id() { return {1, 0}; }
  static X map(X x, const A &a, ull sz) { return m(m.ml(x, a.fi) + sz * a.se); }
};

void Yorisou() {
  INT(N, Q, P);
  m = barrett(P);
  VEC(int, a, N);
  segl_t<MX> seg(move(a));
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) {
      INT(x);
      seg.apply(l, r, {x, 0});
    } else if (op == 2) {
      INT(x);
      seg.apply(l, r, {1, x});
    } else {
      print(seg.prod(l, r));
    }
  }
}

int main() { Yorisou(); }