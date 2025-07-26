#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/IO/fast_io.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  VEC(ll, b, n);
  VEC(ll, c, n);
  FOR(i, 1, n) chmax(b[i], b[i - 1]);
  FOR_R(i, n - 1) chmin(c[i], c[i + 1]);
  FOR(i, n) if (b[i] > c[i]) iroha NO();
  YES(SUM(b) <= m and m <= SUM(c));
}
#include "MeIoN_Lib/Z_H/main.hpp"