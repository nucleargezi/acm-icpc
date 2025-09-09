#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fmt.hpp"
#include "YRS/ds/chtholly/chtholly.hpp"

// #define tests
void Yorisou() {
  ll n, m, q;
  while (IN(n, m, q)) {
    chtholly<bool, int> a(0), b(0);
    a.set(0, n, 0);
    b.set(0, m, 0);
    ll x = 0, y = 0;
    FOR(q) {
      LL(op, l, r);
      --l;
      if (op == 1) {
        a.enumerate_range(l, r, [&](int l, int r, bool f) {
          if (not f) x += r - l;
        });
        a.set(l, r, 1);
      } else {
        b.enumerate_range(l, r, [&](int l, int r, bool f) {
          if (not f) y += r - l;
        });
        b.set(l, r, 1);
      }
      if (x and y) UL(n * m - x * m - y * n + x * y + 1);
      else if (x) UL(n * m - x * m + x);
      else UL(n * m - y * n + y);
    }
  }
}
#include "YRS/Z_H/main.hpp"