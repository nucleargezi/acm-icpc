#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/counting/tri_euler_count.hpp"

// #define tests
using mint = M17;
void Yorisou() {
  int a, b, c;
  while (IN(a, b, c)) {
    UL(tri_euler_count<mint>(a, b, c));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"