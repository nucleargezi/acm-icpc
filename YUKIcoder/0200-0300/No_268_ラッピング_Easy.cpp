#include "YRS/all.hpp"

void Yorisou() {
  VEC(int, a, 3);
  VEC(int, b, 3);
  ll s = inf<ll>;
  vc<int> l(3), r(3);
  iota(all(l), 0);
  iota(all(r), 0);
  do {
    do {
      vc<int> x = rearrange(a, l);
      vc<int> y = rearrange(b, r);
      int a = x[0], b = x[1], c = x[2];
      int d = y[0], e = y[1], f = y[2];
      chmin(s, 2 * (f * (a + b) + d * (b + c) + e * (a + c)));
    } while (next_permutation(all(r)));
  } while (next_permutation(all(l)));
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"