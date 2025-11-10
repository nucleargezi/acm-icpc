#include "YRS/all.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/math/set/subset_convolution.hpp"

// #define tests
using mint = modint<1'000'000'000 + 9>;
void Yorisou() {
  INT(n);
  const int N = 1 << n;
  VEC(mint, a, N);
  VEC(mint, b, N);
  print(subset_convolution(a, b));
}
#include "YRS/Z_H/main.hpp"