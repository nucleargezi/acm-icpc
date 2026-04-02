#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N, T);
  VEC(PLL, a, N);
  ll x = 0;
  for (Z [t, k] : a) {
    if (x + t <= T) x += t;
    else x += min(t, max(0ll, k + T - x) + 1);
  }
  cout << x << '\n';
}
#include "YRS/Z_H/main.hpp"