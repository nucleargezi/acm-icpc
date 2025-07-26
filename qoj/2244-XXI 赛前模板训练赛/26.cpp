#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/set/bit_convolution.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n);
  VEC(mint, a, 1 << n);
  VEC(mint, b, 1 << n);
  print("{}", and_convolution(a, b));
}
#include "MeIoN_Lib/Z_H/main.hpp"