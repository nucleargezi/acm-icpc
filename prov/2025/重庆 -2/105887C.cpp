#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  vector ans(n, vector<int>(n));
  FOR(i, n) {
    if (i & 1) {
      FOR(k, i + 1) ans[i][k] = i + 1;
      FOR(k, i) ans[k][i] = k + 1;
    } else {
      FOR(k, i + 1) ans[k][i] = i + 1;
      FOR(k, i) ans[i][k] = k + 1;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"