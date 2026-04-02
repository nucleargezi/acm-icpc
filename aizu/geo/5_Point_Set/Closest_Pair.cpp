#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"
#include "YRS/ge/pairs/closest_pair.hpp"

// #define tests
using RE = long double;
using P = point<ll>;
void Yorisou() {
  INT(N);
  vector<P> p(N);
  FOR(i, N) {
    REA(x, y);
    p[i].x = ll(x * 1'000'000'0);
    p[i].y = ll(y * 1'000'000'0);
  }
  meion [i, k] = closest_pair(p);
  setp(20);
  UL((p[i] - p[k]).length() / 1'000'000'0);
}
#include "YRS/Z_H/main.hpp"