#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(a, b, n, m, h);
  UL(n + m - binary_search([&](ll x) -> bool {
    ll s{};
    s += n / b * (b - a);
    s += (n + m - x) / b * (h - b);
    iroha s > x - 1;
  }, 0, m));
}
#include "MeIoN_Lib/Z_H/main.hpp"