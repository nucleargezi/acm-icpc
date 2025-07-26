#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/poly/fps_exp.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n);
  VEC(mint, a, n);
  print("{}", fps_exp(a));
}
#include "MeIoN_Lib/Z_H/main.hpp"