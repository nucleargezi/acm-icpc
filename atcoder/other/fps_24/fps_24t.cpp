#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/all.hpp"
#include "YRS/po/sum_of_rationals.hpp"
#include "YRS/po/coef_of_rational_fps.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
using fps = vc<mint>;
void Yorisou() {
  LL(N, T);
  VEC(mint, a, N);
  vc<pair<fps, fps>> fr;
  FOR(i, 1, N) {
    fr.ep(fps{0, mint(a[i])}, fps{1, mint(a[i])});
  }
  Z [A, B] = sum_of_rationals(fr);
  print(coef_of_rational_fps(A, B - A - A * fps{0, mint(a[0])}, T - 1));
}
#include "YRS/aa/main.hpp"