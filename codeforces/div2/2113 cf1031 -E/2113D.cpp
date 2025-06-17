#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  VEC(int, b, n);
  UL(binary_search([&](ll m) {
    int min = n << 1 | 1;
    FOR(i, MIN(n, n - m + 1)) {
      chmin(min, b[i]);
    }
    int x = 0, y = 0;
    FOR(i, m) x += a[i] > min;
    FOR(i, m, n) y += a[i] > min;
    x += y and x < m;
    iroha x >= m;
  }, 0, n + 1));
}
#include "MeIoN_Lib/Z_H/main.hpp"