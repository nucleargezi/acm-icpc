#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/ds/toptree/satt.hpp"

struct sayo {
  using X = struct {
    ll s;
    int mx, mn;
  };

  static X unit() { return {0, -inf<int>, inf<int>}; }

  static X op(const X &L, const X &R) {
    return {L.s + R.s, max(L.mx, R.mx), min(L.mn, R.mn)};
  }

  static constexpr bool commute = 1;

  using A = PLL;

  static A id() { return {1, 0}; }

  static A fu(const A &f, const A &g) {
    return {f.fi * g.fi, f.se * g.fi + g.se};
  }

  static X map(X x, A a, int sz) {
    x.mn *= a.fi, x.mx *= a.fi, x.s *= a.fi;
    x.mn += a.se, x.mx += a.se, x.s += a.se * sz;
    return x;
  }
};

void Yorisou() {
  INT(N, Q);
  VEC(PII, e, N - 1);
  satt<sayo> ds(N);
  FOR(i, N) {
    INT(x);
    ds.set(i, {x, x, x});
  }
  for (Z [a, b] : e) {
    --a, --b;
    ds.link(a, b);
  }
  INT(t);
  --t;
  ds.evert(t);

  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y);
      --x;
      ds.apply_sub(x, t, {0, y});
    } else if (op == 1) {
      IN(t);
      --t;
    } else if (op == 2) {
      INT(x, y, w);
      --x, --y;
      ds.apply_ch(x, y, {0, w});
    } else if (op == 3) {
      INT(x);
      --x;
      print(ds.prod_sub(x, t).mn);
    } else if (op == 4) {
      INT(x);
      --x;
      print(ds.prod_sub(x, t).mx);
    } else if (op == 5) {
      INT(x, y);
      --x;
      ds.apply_sub(x, t, {1, y});
    } else if (op == 6) {
      INT(x, y, w);
      --x, --y;
      ds.apply_ch(x, y, {1, w});
    } else if (op == 7) {
      INT(x, y);
      --x, --y;
      print(ds.prod_ch(x, y).mn);
    } else if (op == 8) {
      INT(x, y);
      --x, --y;
      print(ds.prod_ch(x, y).mx);
    } else if (op == 9) {
      INT(x, y);
      --x, --y;
      if (not ds.in_sub(x, y, t)) {
        ds.cut(x, t);
        ds.link(x, y);
      }
    } else if (op == 10) {
      INT(x, y);
      --x, --y;
      print(ds.prod_ch(x, y).s);
    } else {
      INT(x);
      --x;
      print(ds.prod_sub(x, t).s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}