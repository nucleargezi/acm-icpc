// #include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/lag.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, c);
  VEC(mint, a, n + 1);
  UL(lagrange_interpolate_iota<mint>(a, c, n + 1));
}
#include "MeIoN_Lib/Z_H/main.hpp"