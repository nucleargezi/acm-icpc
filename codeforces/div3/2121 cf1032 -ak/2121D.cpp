#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  VEC(ll, b, n);
  vector<PII> ans;
  meion ad = [&](int op, int i) { ans.emplace_back(op, ++i); };
  FOR(i, n) FOR(i, n - 1) {
    if (a[i] > a[i + 1]) ad(1, i), swap(a[i], a[i + 1]);
  }
  FOR(i, n) FOR(i, n - 1) {
    if (b[i] > b[i + 1]) ad(2, i), swap(b[i], b[i + 1]);
  }
  FOR(i, n) {
    if (a[i] > b[i]) ad(3, i), swap(a[i], b[i]);
  }
  UL(len(ans));
  for (meion x : ans) UL(x);
}
#include "MeIoN_Lib/Z_H/main.hpp"