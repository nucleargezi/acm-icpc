#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/math/poly/convolution.hpp"

// #define tests
using mint = M99;
using poly = vector<mint>;
void Yorisou() {
  LL(n);
  mint p;
  IN(p);
  p /= 100;
  mint q = -p + 1;
  poly mul(n + 1, 1);
  FOR_R(i, n) mul[i] = mul[i + 1] * (q * inv<mint>(i) + 1);
  poly a(n), b(n), c(n);
  FOR(i, 1, n) a[i] = fact<mint>(i - 1) * mul[i + 1];
  FOR(i, 1, n) b[i] = fact_inv<mint>(i - 1) * p.pow(i);
  FOR(i, n) c[i] = fact_inv<mint>(i) * q.pow(i);
  reverse(c);
  vector xz = convolution(a, c);
  poly ans(n);
  FOR(i, 1, n) ans[i] = xz[n - 1 + i] * b[i];
  ans[0] = -SUM<mint>(ans) + n;
  FOR(i, n) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"