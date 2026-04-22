#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/lct/lct_act.hpp"

struct F {
  struct X {
    int lc, rc, s;
  };

  static X op(const X &a, const X &b) {
    if (a.lc == -1) return b;
    if (b.lc == -1) return a;
    X c = a;
    c.rc = b.rc;
    c.s += b.s;
    if (a.rc == b.lc) --c.s;
    return c;
  }

  X unit() { return {-1, 0, 0}; }

  static constexpr bool commute = 0;

  using A = int;

  static A fu(A a, A b) { 
    if (a == -1) return b;
    if (b == -1) return a;
    return b; 
  }

  static A id() { return -1; }
  
  static X map(X x, A f, int sz) {
    if (f == -1) return x;
    return {f, f, 1};
  }
};
void Yorisou() {
  INT(N, Q);
  lct_act<F> g(N);
  FOR(i, N) {
    INT(x);
    g[i]->mx = {x, x, 1};
  }
  FOR(N - 1) {
    INT(x, y);
    --x, --y;
    g.link(x, y);
  }
  FOR(Q) {
    CH(op);
    if (op == 'Q') {
      INT(a, b);
      --a, --b;
      print(g.prod(a, b).s);
    } else {
      INT(a, b, c);
      --a, --b;
      g.apply(a, b, c);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}