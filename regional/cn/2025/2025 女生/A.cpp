#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  LL(N, s, t);
  ll a = t >= s ? t - s : t + N - s, b = N + 1 - a;
  print(a < b ? 1 : 2);
}
#include "YRS/Z_H/main.hpp"