#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ge/all.hpp"

#define tests
using P = point<ll>;
int T = 0;
void Yorisou() {
  cout << std::format("Case {}: ", ++T);
  LL(a, b, c, d);
  ll ans = inf<ll>;
  FOR(2) {
    swap(a, b);
    FOR(2) {
      swap(c, d);
      vector<P> p{{0, 0}, {c, 0}, {c, d}, {0, d}, {0, a}, {-b, a}, {-b, 0}};
      p = rearrange(p, hull(p));
      chmin(ans, convex_polygon<ll>(p).area());
    }
  }
  setp(7);
  print(ans / 2.L);
}
#include "YRS/Z_H/main.hpp"