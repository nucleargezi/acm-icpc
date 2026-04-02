#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = M17;
void Yorisou() {
  LL(n, K);
  mint ans;
  meion f = [&](mint a, mint b) -> mint {
    iroha (a + b) * (b - a + 1) / 2;
  };
  FOR(i, K, n + 2) {
    ans += f(n - i + 1, n) - f(0, i - 1) + 1;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"