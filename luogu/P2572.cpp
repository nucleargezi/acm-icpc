#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"

struct AM {
  struct G {
    int l, r, s, mx, sz;
  };
  G f(const G a, const G &b) {
    if (a.l == -1) return b;
    if (b.l == -1) return a;
    G c{a.l, b.r, a.s + b.s, max(a.mx, b.mx), a.sz + b.sz};
    if (a.l == a.sz) c.l = a.l + b.l;
    if (b.r == b.sz) c.r = b.r + a.r;
    chmax(c.mx, max({c.l, c.r, a.r + b.l}));
    return c;
  }
  static constexpr bool commute = 0;

  using X = array<G, 2>;
  X op(const X &a, const X &b) { return {f(a[0], b[0]), f(a[1], b[1])}; }
  
  G ug() { return {-1, 0, 0, 0, 0}; }
  
  X unit() { return {ug(), ug()}; }

  using A = int;
  A fu(A a, A b) {
    if (b == 2) return 2;
    if (b == 3) return 3;
    return a ^ b;
  }
  A id() { return 0; }

  X map(const X &x, const A &f, int sz) {
    if (f == 2) return sing(0, sz);
    if (f == 3) return sing(1, sz);
    if (f == 1) return {x[1], x[0]};
    return x;
  }

  static X sing(bool x, int sz = 1) {
    X f{};
    f[0] = {sz, sz, sz, sz, sz};
    f[1] = {0, 0, 0, 0, sz};
    if (x == 0) swap(f[0], f[1]);
    return f;
  }
};
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  segl_t<AM> seg(N, [&](int i) { return AM::sing(a[i]); });
  FOR(Q) {
    INT(op, l, r);
    ++r;
    if (op == 0) seg.apply(l, r, 2);
    if (op == 1) seg.apply(l, r, 3);
    if (op == 2) seg.apply(l, r, 1);
    if (op == 3) print(seg.prod(l, r)[0].s);
    if (op == 4) print(seg.prod(l, r)[0].mx);
  }
}

int main() {
  Yorisou();
  return 0;
}