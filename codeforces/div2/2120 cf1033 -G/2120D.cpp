#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

#define tests
using mint = M17;
void Yorisou() {
  LL(a, b, k);
  mint x = mint(k) * (a - 1) + 1;
  mint v = 1;
  FOR(i, a) v *= x - i;
  mint y = (mint)(b - 1) * k * v * fact_inv<mint>(a) + 1;
  UL(x, y);
}
#include "MeIoN_Lib/Z_H/main.hpp"