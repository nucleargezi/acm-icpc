#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/set/subset_poly_compose.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  INT(n);
  VEC(mint, f, 1 << n);
  VEC(mint, g, n + 1);
  UL(subset_poly_compose(f, g));
}
#include "MeIoN_Lib/Z_H/main.hpp"