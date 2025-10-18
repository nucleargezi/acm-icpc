#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/set/subset_log.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  INT(n);
  VEC(mint, a, 1 << n);
  UL(subset_log(a));
}
#include "MeIoN_Lib/Z_H/main.hpp"