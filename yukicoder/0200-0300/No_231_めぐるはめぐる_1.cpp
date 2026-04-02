#include "YRS/all.hpp"

void Yorisou() {
  INT(N);
  VEC(PLL, a, N);
  vc<int> I(N);
  iota(all(I), 0);
  sort(I, [&](int i, int k) {
    PLL x = a[i], y = a[k];
    return x.fi - 30000 * x.se > y.fi - 30000 * y.se;
  });
  Z [x, y] = a[I[0]];
  x -= 30000 * y;
  if (6 * x >= 3000000) {
    YES();
    FOR(6) print(I[0] + 1);
  } else {
    NO();
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"