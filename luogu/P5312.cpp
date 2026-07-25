#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/sort_seg_xor.hpp"

struct MX {
  static constexpr int n = 30;
  struct X {
    array<int, n> a;
    X() : a{} {}
    X(int x) : a{} {
      FOR(i, n) if (x >> i & 1) ++a[i];
    }
    ll f() const {
      ll s = 0;
      FOR(i, n) s += (1ll << i) * a[i];
      return s;
    }
  };
  static X op(const X &a, const X &b) {
    X c(a);
    FOR(i, n) c.a[i] += b.a[i];
    return c;
  }
  static X unit() { return X(); }
  static constexpr bool commute = 1;
  static X key_map(const X &a, uint x, int sz) {
    X c(a);
    FOR(i, n) {
      if (x >> i & 1) {
        c.a[i] = sz - c.a[i];
      }
    }
    return c;
  }
};

void Yorisou() {
  INT(N);
  VEC(uint, a ,N);
  INT(Q);
  a.resize(N + Q);
  vc<MX::X> dat(all(a));
  sort_seg_xor<MX> seg(a, dat);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(x);
      seg.set(N++, x, x);
    } else if (op == 2) {
      INT(l, r);
      --l;
      print(seg.prod(l, r).f());
    } else if (op == 3) {
      INT(x);
      seg.apply(0, N, x);
    } else {
      seg.sort_inc(0, N);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}