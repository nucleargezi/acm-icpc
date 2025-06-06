#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/poly/poly_divmod.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, m);
  VEC(mint, a, n + 1);
  VEC(mint, b, m + 1);
  meion [x, y] = poly_divmod(a, b);
  UL(x);
  UL(y);
}
#include "MeIoN_Lib/Z_H/main.hpp"