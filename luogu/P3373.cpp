#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/avl/avl_sayo.hpp"
#include "YRS/mod/barrett.hpp"

barrett md;
struct MX {
  using X = int;
  using A = pair<int, int>;

  static X op(X x, X y) { return md(x + y); }

  static X unit() { return 0; }

  static A fu(const A &f, const A &g) {
    return {md.ml(f.fi, g.fi), md(md.ml(f.se, g.fi) + g.se)};
  }

  static A id() { return {1, 0}; }

  static X map(X x, const A &a, ll sz) {
    return md(md.ml(x, a.fi) + md.ml(sz, a.se));
  }

  static constexpr bool commute = 1;
};

void Yorisou() {
  INT(N, Q, P);
  md = barrett(P);
  VEC(int, a, N);
  avl_sayo<MX> g;
  Z t = g.newnode(a);
  FOR(Q) {
    INT(op, l, r);
    --l;
    if (op == 1) {
      INT(x);
      t = g.apply(t, l, r, {x, 0});
    } else if (op == 2) {
      INT(x);
      t = g.apply(t, l, r, {1, x});
    } else {
      print(g.prod(t, l, r));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}