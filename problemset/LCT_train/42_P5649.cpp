#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/toptree/satt.hpp"

#define tests 0
#define fl 0
#define DB 10
struct MX {
  using X = struct {
    ll s;
    int mx, mn;
  };
  static constexpr X unit() { return {0, -inf<int>, inf<int>}; }
  static constexpr X make(int x) { return {x, x, x}; }
  static constexpr X op(X L, X R) {
    return {L.s + R.s, max(L.mx, R.mx), min(L.mn, R.mn)};
  }
};
struct MA {
  using X = pair<ll, ll>;
  static constexpr X op(const X &f, const X &g) {
    return {f.fi * g.fi, f.se * g.fi + g.se};
  }
  static constexpr X unit() {  return {1, 0}; }
};
struct AM {
  using MX = ::MX;
  using MA = ::MA;
  using X = MX::X;
  using A = MA::X;
  static constexpr X act(X x, A a, int sz) {
    x.mn *= a.fi, x.mx *= a.fi, x.s *= a.fi;
    x.mn += a.se, x.mx += a.se, x.s += a.se * sz;
    return x;
  }
};
void Yorisou() {
  INT(N, Q);
  SATT<AM> satt(N);
  VEC(PII, e, N - 1);
  FOR(i, N) {
    INT(x);
    satt.set(i, MX::make(x));
  }
  for (Z [x, y] : e) {
    --x, --y;
    satt.link(x, y);
  }
  INT(rt);
  --rt;
  satt.evert(rt);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y);
      --x;
      satt.apply_sub(x, rt, {0, y});
    } else if (op == 1) {
      IN(rt);
      --rt;
    } else if (op == 2) {
      INT(x, y, w);
      --x, --y;
      satt.apply_chain(x, y, {0, w});
    } else if (op == 3) {
      INT(x);
      --x;
      print(satt.prod_sub(x, rt).mn);
    } else if (op == 4) {
      INT(x);
      --x;
      print(satt.prod_sub(x, rt).mx);
    } else if (op == 5) {
      INT(x, y);
      --x;
      satt.apply_sub(x, rt, {1, y});
    } else if (op == 6) {
      INT(x, y, w);
      --x, --y;
      satt.apply_chain(x, y, {1, w});
    } else if (op == 7) {
      INT(x, y);
      --x, --y;
      print(satt.prod_chain(x, y).mn);
    } else if (op == 8) {
      INT(x, y);
      --x, --y;
      print(satt.prod_chain(x, y).mx);
    } else if (op == 9) {
      INT(x, y);
      --x, --y;
      if (not satt.in_sub(x, y, rt)) {
        satt.cut(x, rt);
        satt.link(x, y);
      }
    } else if (op == 10) {
      INT(x, y);
      --x, --y;
      print(satt.prod_chain(x, y).s);
    } else {
      INT(x);
      --x;
      print(satt.prod_sub(x, rt).s);
    }
  }
}
#include "YRS/Z_H/main.hpp"