#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

#define tests
using mint = M99;
meion ans = []() {
  constexpr int N = 5'000'01;
  vector<mint> a(N), b(N), c(N);
  FOR(i, 1, N) {
    meion fac = fact<mint>(i - 1);
    a[i] = a[i - 1] * i + fac;
    b[i] = b[i - 1] * i + a[i - 1] * 2 + fac;
    c[i] = c[i - 1] * i + b[i - 1] * 3 + a[i - 1] * 3 + fac;
  }
  iroha c;
}();
void Yorisou() {
  LL(n);
  UL(ans[n]);
}
#include "MeIoN_Lib/Z_H/main.hpp"