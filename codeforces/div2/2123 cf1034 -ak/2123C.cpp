#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  meion b = a, c = a;
  FOR(i, 1, n) chmin(b[i], b[i - 1]);
  FOR_R(i, n - 1) chmax(c[i], c[i + 1]);
  string ans(n, '0');
  FOR(i, n) ans[i] += a[i] == b[i] or a[i] == c[i];
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"