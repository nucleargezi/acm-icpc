#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  set<PLL> a, b;
  VEC(PLL, ps, n);
  if (n == 1) iroha print("1");
  for (meion [x, y] : ps) {
    a.emplace(x, y);
    b.emplace(y, x);
  }
  ll ans = inf<ll>;
  meion f = [&](PLL p) -> void {
    meion [x, y] = p;
    a.extract({x, y});
    b.extract({y, x});
    ll h = a.rbegin()->first - a.begin()->first + 1;
    ll w = b.rbegin()->first - b.begin()->first + 1;
    if (h * w >= n) {
      chmin(ans, h * w);
    } else {
      chmin(ans, h * w + MIN(h, w));
    }
    a.emplace(x, y);
    b.emplace(y, x);
  };
  for (meion x : ps) f(x);
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"