#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/online_exp.hpp"
#include "YRS/po/cg/label_tree.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
void Yorisou() {
  INT(N, op);
  if (op == 1) {
    fps A(N + 1), B = count_label_tree<mint>(N);
    FOR(i, 1, N + 1) B[i] *= ifac(i) * i;
    online_exp<mint> expB;
    FOR(i, 1, N + 1) {
      A[i] = expB(B[i - 1]);
      B[i] = B[i] - A[i];
    }
    FOR(i, 2, N + 1) print(A[i] * fac(i) * inv<mint>(i));
  } else {  
    fps f = count_label_tree<mint>(N);
    FOR(i, 2, N + 1) {
      if (~i & 1) f[i] -= mint(i).pow(i / 2 - 1) * ifac(i / 2) * fac(i - 1);
      print(f[i]);
    }
  }
}
#include "YRS/aa/main.hpp"