#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N, x, y);
  ll ans = -1ll * x * (x + 1) / 2;
  FOR(i, 1, N + 1) ans += 1ll * i * (i + 1) / 2;
  FOR(i, 1, N + 1) {
    ll s = std::min(i, N - i);
    ans += s * (i + 1);
    ans -= s * (s + 1) / 2;
  }
  int l = y - 1, r = x - y;
  FOR(i, x) {
    if (i < l) ans += l - i;
    if (i < r) ans += r - i;
  }
  ll s = std::min(x, N - x);

  FOR(i, s) ans -= x - i;
  FOR(i, s) ans += std::max(0, l - i) + std::max(0, r - i);
  print(ans);
}
#include "YRS/Z_H/main.hpp"