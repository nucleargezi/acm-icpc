#include "YRS/Z_H/MeioN.hpp"
#include "YRS/MeIoN_all.hpp"
#include "YRS/math/poly/fps_pow.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, k);
  VEC(mint, a, n);
  UL(fps_pow(a, k));
}
#include "YRS/Z_H/main.hpp"