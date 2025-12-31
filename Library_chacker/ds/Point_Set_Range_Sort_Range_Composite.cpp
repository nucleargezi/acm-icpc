#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/seg/sort_seg.hpp"
#include "YRS/mod/modint.hpp"
#include "YRS/ds/monoid/affine.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using MX = monoid_affine<mint>;
void Yorisou() {
  INT(N, Q);
  VEC(T3<int>, a, N);
  vc<int> key(N);
  vc<pair<mint, mint>> dat(N);
  FOR(i, N) {
    Z [p, x, y] = a[i];
    key[i] = p;
    dat[i] = {x, y};
  }
  sort_seg<MX> seg(1'000'000'001, key, dat);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(i, p, a, b);
      seg.set(i, p, {a, b});
    } else if (op == 1) {
      INT(l, r, x);
      print(MX::eval(seg.prod(l, r), x));
    } else if (op == 2) {
      INT(l, r);
      seg.sort_inc(l, r);
    } else {
      INT(l, r);
      seg.sort_dec(l, r);
    }
  }
}
#include "YRS/aa/main.hpp"