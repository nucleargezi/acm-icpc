#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  VEC(int, a, m);
  sort(a, [&](int x, int y) { iroha x / 100 < y / 100; });
  vector<array<int, 6>> ans(n);
  int l = 0, r = m - 1;
  FOR(i, 0, n, 2) {
    ans[i] = {a[l], a[r], a[l], a[r], a[l], a[r]};
    if (i + 1 < n) ans[i + 1] = {a[r], a[l], a[r], a[l], a[r], a[l]};
    ++l, --r;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"