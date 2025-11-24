#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(K);
  K *= K;
  Z f = [&](ll x, ll y) -> ll {
    return x * x * 3 + y * y * 3 + x * y * 3 + x * 3 + y * 3 + 1;
  };
  if (f(0, 0) > K) return print(0);
  ll x = 0, y = 0;
  while (f(x + 1, y) <= K) ++x;
  ll t = x, ans = 0;
  while (1) {
    while (f(x, y + 1) <= K) ++y;
    ans += y + 1;
    if (--x < 0) break;
  }
  ans = (ans - 2 * t - 1) * 6 + 6 * t + 1;
  print(ans);
}
#include "YRS/Z_H/main.hpp"