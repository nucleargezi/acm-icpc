#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/ofps.hpp"

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
  INT(N);
  VEC(mint, A, N + 1);
  VEC(mint, B, N + 1);

  ofps X;
  dat a = X.val(std::move(A)), b = X.val(std::move(B));
  pip h = X.var();
  h.set(X.sing(0));
  h.set((a * dat(h).exp() + b).inte());
  print((1 + dat(h)).ke(N + 1));
}
#include "YRS/aa/main.hpp"