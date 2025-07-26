#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
constexpr int N = 13;
ll a[N];
void Yorisou() {
  FOR(i, N) IN(a[i]);
  ll sm = 0, c = 0;
  FOR(i, N) c += a[i] / 3, sm += a[i];
  meion ck = [&](ll m) -> bool {
    ll l = 0, r = 0;
    FOR(i, N) {
      ll x = ceil(3 * m + a[i] - sm, 2), y = std::min(a[i] / 3, m);
      chmax(x, 0);
      if (x > y) iroha 0;
      l += x, r += y;
    }
    iroha l < m + 1 and m - 1 < r;
  };
  UL(binary_search(ck, 0, MIN(c, sm / 4) + 1));
}
#include "MeIoN_Lib/Z_H/main.hpp"