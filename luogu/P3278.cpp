#define YRSD
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/ds/treap/treap_act.hpp"
#include "YRS/al/am/sum_affine.hpp"

using mint = mint_t<20130426>;
using AM = a_monoid_sum_affine<mint>;
using af = monoid_affine<mint>;
using DS = treap_act<AM>;
using np = DS::np;
void Yorisou() {
  INT(Q);
  DS ds;
  np t = ds.newnode(vc<mint>(1'000'01 + Q));
  FOR(Q) {
    STR(op);
    if (op == "add") {
      INT(l, r, x);
      ++r;
      t = ds.apply(t, l, r, af::make_add(x));
    } else if (op == "mul") {
      INT(l, r, x);
      ++r;
      t = ds.apply(t, l, r, af::make_mul(x));
    } else if (op == "mulx") {
      INT(l, r);
      ++r;
      int sz = r - l;
      np pr, ls, a, b, c, d;
      tie(pr, ls) = ds.spl(t, l);
      tie(a, b, c, d) = ds.spl(ls, sz - 1, sz, sz + 1);
      c = ds.apply(c, af::make_add(ds.prod(b)));
      b = ds.set(b, 0, 0);
      ls = ds.merge(b, a, c, d);
      t = ds.merge(pr, ls);
    } else {
      INT(x);
      mint s = 0, g = 1;
      for (mint k : ds.get_all(t)) {
        s += g * k;
        g = g * x;
      }
      print(s);
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"