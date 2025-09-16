#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N, K);
  VEC(ll, a, N);
  sort(a, greater());
  vector c = pre_sum(a);
  print(binary_search([&](ll x) -> bool {
    int y = lower_bound(c, x);
    y += c[y] < x;
    int nd = N - y;
    return nd <= (x - y) / K;
  }, SUM(a), N - 1));
}
#include "YRS/Z_H/main.hpp"