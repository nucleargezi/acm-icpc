#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/poly/fps_sqrt.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n);
  VEC(mint, a, n);
  UL(fps_sqrt(a));
}
#include "MeIoN_Lib/Z_H/main.hpp"