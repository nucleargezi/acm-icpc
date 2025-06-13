#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
using RE = long double;
void Yorisou() {
  LL(n, m, x, y);
  if (not n and not m) iroha UL(0);
  if (not m) iroha UL(MAX(n * y, x, x + (n - 1) * y));
  if (n) {
    ll res = n * y;
    bool f = x > y;
    res += f ? x : y * m;
    if (x <= y * (n + 1)) {
      int r = binary_search([&](int s) -> bool {
        iroha x <= y * (s + 1);
      }, n, -1);
      ll rr = (n - r) * y + (r ? x : 0) + m * y;
      chmax(res, rr);
    }
    UL(res);
  } else
    UL(x > y ? x : m * y);
}
#include "MeIoN_Lib/Z_H/main.hpp"