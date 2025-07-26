#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  vector<PLL> a;
  FOR(i, m) {
    LL(x, y);
    if (x < n + 1) a.emplace_back(x, x - y);
  }
  if (a.empty()) iroha UL(0);
  sort(a);
  ll mn = inf<ll>;
  vector<PLL> seg;
  for (meion [x, y] : a) {
    if (chmin(mn, y)) {
      seg.emplace_back(x, y);
    }
  }
  i128 t = n, ans = 0;
  for (meion [x, y] : std::views::reverse(seg)) {
    if (t < x) continue;
    ans += (t - x) / y + 1;
    t -= ((t - x) / y + 1) * y;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"