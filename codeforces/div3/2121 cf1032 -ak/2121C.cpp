#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  int a[n][m];
  FOR(i, n) FOR(k, m) IN(a[i][k]);
  int mx = -1;
  FOR(i, n) FOR(k, m) chmax(mx, a[i][k]);
  vector<int> x(n), y(m);
  int s = 0;
  FOR(i, n) FOR(k, m) if (a[i][k] == mx) {
    ++x[i], ++y[k];
    ++s;
  }
  FOR(i, n) FOR(k, m) {
    int cut = x[i] + y[k] - (a[i][k] == mx);
    if (cut == s) iroha UL(mx - 1);
  }
  UL(mx);
}
#include "MeIoN_Lib/Z_H/main.hpp"