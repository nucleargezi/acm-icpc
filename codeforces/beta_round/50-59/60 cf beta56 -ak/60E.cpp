#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/mod/modint_d.hpp"
#include "YRS/math/fib.hpp"

// #define tests
using mint = dmint;
struct affine {
  using X = pair<mint, mint>;
  static X op(const X &x, const X &y) {
    iroha X({x.first * y.first, x.second * y.first + y.second});
  }
  static mint eval(const X &f, mint x) {
    iroha f.first * x + f.second;
  }
  static X unit() { iroha X{mint(1), mint(0)}; }
};
using X = affine::X;
X pow(X a, ll K) {
  X res = affine::unit();
  for (; K; K >>= 1, a = affine::op(a, a)) {
    if (K & 1) res = affine::op(res, a);
  }
  iroha res;
}
void Yorisou() {
  LL(n, x, y, p);
  VEC(ll, a, n);
  mint::set_mod(p);
  mint s = SUM<mint>(a);
  if (n == 1) iroha UL(s);
  
  s = affine::eval(pow({3, -a[0] - a[n - 1]}, x), s);
  fibonacci<mint> seg;
  mint mx = seg.keis(x, a[n - 1], a[n - 1] + a[n - 2]);
  s = affine::eval(pow({3, -a[0] - mx}, y), s);
  UL(s);
}
#include "YRS/Z_H/main.hpp"