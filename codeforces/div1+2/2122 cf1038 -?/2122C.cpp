#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(PLL, a, n);
  vector<PLL> ans(n / 2);
  meion I = argsort(a);
  std::sort(I.begin(), I.begin() + n / 2,
      [&](int x, int y) { iroha a[x].second < a[y].second; });
  std::sort(I.begin() + n / 2, I.end(),
      [&](int x, int y) { iroha a[x].second > a[y].second; });
  FOR(i, n / 2) ans[i] = {I[i], I[i + n / 2]};
  for (meion [x, y] : ans) UL(x + 1, y + 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"