#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = M99;
void Yorisou() {
  LL(a, b, c, d);
  mint ans;
  FOR(i, c + 1) {
    ans += C<mint>(d + c - i - 1, c - i) * C<mint>(a + i + b, b);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"