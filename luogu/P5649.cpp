#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/lct/lct_sub_sayo.hpp"

struct MX {
  static constexpr bool commute = 1;
  struct X {
    ll s;
    int mx, mn;
    X(ll s, int mx, int mn) : s(s), mx(mx), mn(mn) {}
    X() : X(0, ine<int>, inf<int>) {}
    X(int x) : X(x, x, x) {}
  };
  using A = PLL;
  static X unit() { return X(); }
  static X op(const X &a, const X &b) {
    return {a.s + b.s, max(a.mx, b.mx), min(a.mn, b.mn)};
  }
  static A id() { return {1, 0}; }
  static A fu(const A &a, const A &b) {
    return {a.fi * b.fi, a.se * b.fi + b.se};
  }
  static X map(X x, A f, ll n) {
    if (not n) return x;
    x.s = x.s * f.fi + f.se * n;
    x.mx = (ll)x.mx * f.fi + f.se;
    x.mn = (ll)x.mn * f.fi + f.se;
    return x;
  }
  static X make(int x) { return {(ll)x, x, x}; }
};

void Yorisou() {
  INT(N, Q);
  lct_sub_sayo<MX> g(N);
  VEC(PII, es, N - 1);
  FOR(i, N) {
    INT(x);
    g.set(i, x);
  }
  for (Z [a, b] : es) g.link(a - 1, b - 1);
  INT(rt);
  --rt;
  int x, y, z;
  FOR(Q) {
    INT(op);
    if (op == 0) {
      IN(x, y), g.apply_sub(x - 1, rt, {0, y});
    } else if (op == 1) {
      IN(rt), --rt;
    } else if (op == 2) {
      IN(x, y, z), g.apply(x - 1, y - 1, {0, z});
    } else if (op == 3) {
      IN(x), print(g.prod_sub(x - 1, rt).mn);
    } else if (op == 4) {
      IN(x), print(g.prod_sub(x - 1, rt).mx);
    } else if (op == 5) {
      IN(x, y), g.apply_sub(x - 1, rt, {1, y});
    } else if (op == 6) {
      IN(x, y, z), g.apply(x - 1, y - 1, {1, z});
    } else if (op == 7) {
      IN(x, y), print(g.prod(x - 1, y - 1).mn);
    } else if (op == 8) {
      IN(x, y), print(g.prod(x - 1, y - 1).mx);
    } else if (op == 9) {
      IN(x, y);
      --x, --y;
      g.evert(rt);
      if (g.lca(x, y) == x) continue;
      g.cut_fa(x);
      g.link(x, y);
    } else if (op == 10) {
      IN(x, y), print(g.prod(x - 1, y - 1).s);
    } else {
      IN(x), print(g.prod_sub(x - 1, rt).s);
    }
  }
}

int main() { Yorisou(); }