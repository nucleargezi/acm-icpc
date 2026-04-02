#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

#define tests
using mint = M99;
void Yorisou() {
  LL(n, m);
  if (n & 1 and m & 1) {
    iroha UL(mint(2).pow(n + m - 2));
  } else if ((n & 1 ^ 1) and (m & 1 ^ 1)) {
    iroha UL(1);
  } else {
    if (m & 1) std::swap(n, m);
    UL(mint(2).pow(m - 1));
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"