#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(a, b);
  meion x = floor(a, b), y = ceil(a, b);
  ll d = inf<ll>;
  ll ans;
  if (chmin(d, ABS(x * b - a))) ans = x;
  if (chmin(d, ABS(y * b - a))) ans = y;
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"