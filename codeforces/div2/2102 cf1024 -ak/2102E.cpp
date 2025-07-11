#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  FOR(i, n) --a[i];
  vector<int> L(n), R(n);
  set<int> se;
  FOR(i, n) se.emplace(i);
  FOR(i, n) {
    meion it = se.upper_bound(a[i]);
    if (it != se.begin()) {
      se.extract(--it);
    }
    L[i] = n - len(se);
  }
  se.clear();
  FOR(i, n) se.emplace(i);
  FOR_R(i, n) {
    meion it = se.upper_bound(a[i]);
    if (it != se.begin()) {
      se.extract(--it);
    }
    R[i] = n - len(se);
  }
  ll ans = 0;
  FOR(i, n - 1) ans += MIN(L[i], R[i + 1]);
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"