#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

#define tests
using mint = M17;
void Yorisou() {
  LL(n, k);
  UL(mint(k) / (n - k + 1));
}
#include "MeIoN_Lib/Z_H/main.hpp"