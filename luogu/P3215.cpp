#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/spl/splay_sayo_re_nc.hpp"

struct S {
  struct X {
    int s, mn, mx, sz;

    int eval() {
      int a = -mn, b = s + a;
      return ceil(a, 2) + ceil(b, 2);
    }
  };

  static X op(const X &a, const X &b) {
    return {
        a.s + b.s, min(a.mn, a.s + b.mn), max(a.mx, a.s + b.mx), a.sz + b.sz};
  }

  static X unit() { return {0, 0, 0, 0}; }

  using A = char;

  static A id() { return 0; }

  static A fu(A a, A b) {
    if (b == 0) return a;
    if (b == 2 or b == 3) return b;
    if (a == 0) return 1;
    if (a == 1) return 0;
    if (a == 2) return 3;
    return 2;
  }

  static X map(const X &x, A f, int sz) {
    if (f == 0) return x;
    if (f == 1) return {-x.s, -x.mx, -x.mn, x.sz};
    if (f == 2) return {sz, 0, sz, sz};
    return {-sz, -sz, 0, sz};
  }
};

S::X sing(char c) {
  if (c == '(') return {1, 0, 1, 1};
  return {-1, -1, 0, 1};
}

using DS = splay_sayo_re_nc<S>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  STR(s);
  vc<S::X> dat(N);
  FOR(i, N) dat[i] = sing(s[i]);
  DS g;
  np t = g.newnode(dat);
  FOR(Q) {
    STR(op);
    INT(l, r);
    --l;
    if (op[0] == 'R') {
      CH(c);
      g.apply(t, l, r, c == '(' ? 2 : 3);
    } else if (op[0] == 'S') {
      g.rev(t, l, r);
    } else if (op[0] == 'I') {
      g.apply(t, l, r, 1);
    } else {
      print(g.prod(t, l, r).eval());
    }
  }
}

int main() {
  Yorisou();
  return 0;
}