#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  int n, m;
  while (IN(n, m)) {
    ll ans = 0;
    FOR(i, 1, MIN(n + 1, 2017)) FOR(k, 1, MIN(m + 1, 2017)) {
      if (i * k % 2016 == 0) {
        ans += ((n - i) / 2016 + 1) * ((m - k) / 2016 + 1);
      }
    }
    print("{}", ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"