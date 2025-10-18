#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/poly/fps_inv.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n);
  VEC(mint, a, n);
  UL(fps_inv(a));
}
#include "MeIoN_Lib/Z_H/main.hpp"