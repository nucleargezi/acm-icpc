// #include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint_d.hpp"
#include "MeIoN_Lib/math/poly/convolution.hpp"

// #define tests
using mint = dmint;
void Yorisou() {
  LL(n, m, mod);
  mint::set_mod(mod);
  VEC(mint, a, n + 1);
  VEC(mint, b, m + 1);
  UL(convolution(a, b));
}
#include "MeIoN_Lib/Z_H/main.hpp"