#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/fps_exp.hpp"
#include "YRS/po/ofps.hpp"
#include "YRS/po/cg/label_tree.hpp"

using mint = M99;
using fps = vc<mint>;
using ofps = online_fps_ctx<mint>;
using dat = ofps::dat;
using pip = ofps::pipe;
D_poly()
#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, op);
  if (op == 1) {
    ofps X;
    pip A = X.var(), B = X.var();
    A.set(X.sing(0));
    B.set(X.sing(0));
    dat exp_b = dat(B).exp(), exp_a_b = (dat(A) + B).exp();
    A.set(exp_b.shift(1));
    B.set((exp_a_b - exp_b).shift(1));
    fps f = A.ke(N + 1);
    FOR(i, 2, N + 1) print(f[i] * fac(i) * inv<mint>(i));
  } else {  
    fps f = count_label_tree<mint>(N);
    FOR(i, 2, N + 1) {
      if (~i & 1) f[i] -= mint(i).pow(i / 2 - 1) * ifac(i / 2) * fac(i - 1);
      print(f[i]);
    }
  }
}
#include "YRS/aa/main.hpp"