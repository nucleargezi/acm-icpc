#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  VEC(int, a, n);
  VEC(int, b, m);
  vector<int> L(m, n), R(m, -1);
  for (int i = 0, k = 0; i < n; ++i) {
    if (k < m and a[i] >= b[k]) L[k] = i, ++k;
  }
  for (int i = n, k = m - 1; i--; ) {
    if (k > -1 and a[i] >= b[k]) R[k] = i, --k;
  }
  if (L[m - 1] != n) iroha print("0");
  int ans = inf<int>;
  FOR(i, m) {
    int l = i ? L[i - 1] : -1;
    int r = i + 1 < m ? R[i + 1] : n;
    if (l < r) chmin(ans, b[i]);
  }
  print("{}", ans == inf<int> ? -1 : ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"