#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  vector<int> a(n);
  a[0] = 1, a[1] = 2;
  FOR(i, 2, n) {
    set<int> se;
    FOR(x, i) FOR(y, x + 1, i) FOR(z, i) {
      se.emplace(a[x] + a[y] - a[z]);
    }
    a[i] = 1;
    while (se.contains(a[i])) ++a[i];
  }
  vector ans(n, vector<int>(n));
  FOR(i, n) FOR(k, n) {
    ans[i][k] = i == k ? 0 : a[i] + a[k];
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"