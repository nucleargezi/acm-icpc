#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/lct/lct_sayo.hpp"

struct MX {
  struct X {
    int l, r, c;
    X(int l, int r, int c) : l(l), r(r), c(c) {}
    X(int x) : X(x, x, 0) {}
    X() : X(0, 0, 0) {}
  };
  using cp = const X &;
  static X unit() { return X(); }
  static X op(cp a, cp b) { return {a.l, b.r, a.c + b.c + (a.r == b.l)}; }
  using A = int;
  static A id() { return -1; }
  static A fu(A a, A b) { return b == -1 ? a : b; }
  static X map(cp a, A f, int sz) {
    if (f != -1) return {f, f, sz - 1};
    return a;
  }
  static constexpr bool commute = 0;
};

void Yorisou() {
  INT(N, Q);
  lct_sayo<MX> g(N);
  FOR(i, N) g.a[i].mx = N + Q - i;
  FOR(i, N - 1) {
    INT(a, b);
    --a, --b;
    g.link(a, b);
  }
  FOR(i, Q) {
    INT(op, a, b);
    --a, --b;
    if (op == 1) g.apply(a, b, i);
    else print(g.prod(a, b).c);
  }
}

int main() {
  INT(T);
  FOR(T) Yorisou();
}