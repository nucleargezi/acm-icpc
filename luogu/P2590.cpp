#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/tr/gbt/gbt_monoid_commute.hpp"

#define tests 0
#define fl 0
#define DB 10
struct MX {
  using X = struct {
    ll s, mx;
  };
  static constexpr X op(const X &L, const X &R) {
    return {L.s + R.s, max(L.mx, R.mx)};
  }
  static constexpr X unit() {
    return {0, -inf<ll>};
  }
  static constexpr bool commute = true;
};
void Yorisou() {
  INT(N);
  graph g(N);
  g.read_tree();
  VEC(int, a, N);
  vc<MX::X> dat(N);
  FOR(i, N) dat[i] = {a[i], a[i]};
  tree v(g);
  GBT_monoid_commute<decltype(v), MX> seg(v, dat);
  INT(Q);
  FOR(Q) {
    STR(op);
    if (op == "QMAX") {
      INT(x, y);
      --x, --y;
      print(seg.prod(x, y).mx);
    } else if (op == "QSUM") {
      INT(x, y);
      --x, --y;
      print(seg.prod(x, y).s);
    } else {
      INT(x, y);
      --x;
      seg.set(x, {y, y});
    }
  }
}
#include "YRS/aa/main.hpp"