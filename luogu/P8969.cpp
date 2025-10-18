#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/seg/dual_seg.hpp"

// #define tests
struct mono {
  using X = struct dat {
    bool pop;
    ll f, t;
    array<u8, 50> to;

    constexpr bool operator==(const dat &p) const {
      return pop == p.pop and f == p.f and t == p.t and to == p.to;
    }
    ll keis(ll x) { return pop ? to[popcount(x + f)] + t : x + t; }
  };

  static constexpr X unit() { return {false, 0, 0, {}}; }
  static constexpr X op(const X &L, const X &R) {
    X res = unit();
    if (L.pop and R.pop) {
      res.pop = true;
      res.f = L.f, res.t = R.t;
      FOR(i, 50) res.to[i] = R.to[popcount(L.to[i] + L.t + R.f)];
    } else if (not R.pop) {
      res = L;
      res.t += R.t;
    } else {
      res = R;
      res.f += L.t;
    }
    return res;
  }
  static constexpr X make_add(ll x) {
    X a = unit();
    a.t = x;
    return a;
  }
  static constexpr X make_pop() {
    X a = unit();
    a.pop = true;
    iota(a.to.begin(), a.to.end(), 0);
    return a;
  }
  static constexpr bool commute = false;
};
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  dual_seg<mono> seg(N);
  FOR(Q) {
    CH(op);
    if (op == 'A') {
      INT(l, r, x);
      --l;
      seg.apply(l, r, mono::make_add(x));
    } else if (op == 'P') {
      INT(l, r);
      --l;
      seg.apply(l, r, mono::make_pop());
    } else {
      INT(x);
      --x;
      print(seg.get(x).keis(a[x]));
    }
  }
}
#include "YRS/Z_H/main.hpp"