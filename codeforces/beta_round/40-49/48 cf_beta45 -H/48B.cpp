#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  int c[n + 1][m + 1]{};
  FOR(i, n) FOR(k, m) IN(c[i + 1][k + 1]);
  LL(a, b);
  FOR(i, 1, n + 1) FOR(k, m) {
    c[i][k + 1] += c[i][k];
  }
  FOR(i, 1, n + 1) FOR(k, 1, m + 1) {
    c[i][k] += c[i - 1][k];
  }
  int ans = inf<int>;
  FOR(i, n - a + 1) FOR(k, m - b + 1) {
    chmin(ans, c[i + a][k + b] + c[i][k] - c[i][k + b] - c[i + a][k]);
  }
  swap(a, b);
  FOR(i, n - a + 1) FOR(k, m - b + 1) {
    chmin(ans, c[i + a][k + b] + c[i][k] - c[i][k + b] - c[i + a][k]);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"