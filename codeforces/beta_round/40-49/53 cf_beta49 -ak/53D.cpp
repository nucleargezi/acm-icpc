#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  VEC(int, b, n);
  vector<PII> ans;
  while (1) {
    bool f = 0;
    FOR(l, n) if (a[l] != b[l]) {
      f = 1;
      int r = l;
      FOR(k, l + 1, n) {
        if (b[k] == a[l]) {
          r = k;
          break;
        }
      }
      FOR_R(i, l, r) {
        ans.emplace_back(i + 1, i + 2);
        swap(b[i], b[i + 1]);
      }
      break;
    }
    if (not f) break;
  }
  UL(len(ans));
  FOR(i, len(ans)) UL(ans[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"