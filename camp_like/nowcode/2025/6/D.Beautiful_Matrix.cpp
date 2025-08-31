#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/poly/fps_pow.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  LL(n, m);
  if (n == 1) iroha UL(1);
  vector<mint> f(m + 1);
  FOR(i, m + 1) f[i] = C<mint>(n + i - 1, i);
  f = fps_pow(f, n - 1);
  UL(SUM<mint>(f));
}
#include "MeIoN_Lib/Z_H/main.hpp"