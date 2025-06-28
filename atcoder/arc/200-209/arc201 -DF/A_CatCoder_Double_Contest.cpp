#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  ll sa = 0, sc = 0, smx = 0, smy = 0, q = 0;
  FOR(i, n) {
    LL(a, b, c);
    sa += a, sc += c;
    ll L = MAX(0ll, a + c - b);
    ll mnx = MAX(0ll, L - c);
    smx += mnx;
    smy += MIN(c, L);
    q += MIN(a, L) - mnx;
  }
  UL(binary_search([&](ll m) -> bool {
    if (not m) iroha 1;
    if (sa < m or sc < m or sa - smx < m) iroha 0;
    iroha MIN(q, sa - smx - m) >= MAX(0ll, m - sc + smy);
  }, 0, 400000000000001ll));
}
#include "MeIoN_Lib/Z_H/main.hpp"