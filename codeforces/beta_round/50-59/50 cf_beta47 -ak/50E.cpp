#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  ll ans = 0;
  constexpr int N = 2'000'000'1, B = N >> 1;
  vector<int> c(N);
  FOR(i, 1, n + 1) {
    ans += MIN(i * i, m) << 1;
    ll l = std::ceil(std::sqrt(MAX(0ll, i * i - m))), r = std::sqrt(i * i - 1);
    ++c[-i + l + B], --c[-i + r + 1 + B];
    ++c[-i - r + B], --c[-i - l + 1 + B];
  }
  FOR(i, 1, N) c[i] += c[i - 1], ans -= MAX(0, c[i] - 1);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"