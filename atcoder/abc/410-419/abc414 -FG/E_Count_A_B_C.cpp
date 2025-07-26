#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n);
  mint ans = mint(n + 1) * n / 2;
  for (ll i = 1, g; i < n + 1; i = n / (n / i) + 1) {
    ans -= mint(n / i) * (n / (n / i) - i + 1);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"