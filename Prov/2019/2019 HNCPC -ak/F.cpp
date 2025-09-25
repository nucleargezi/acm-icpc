#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint.hpp"

// #define tests
using mint = M17;
int N, a, b, c, d;
void yorisou() {
  print(mint(a + c) * (b + d) * (N - 1) * N / 2 + (mint(a) + b + c + d) * N + 1);
}
void Yorisou() {
  while (IN(N, a, b, c, d)) yorisou();
}
#include "YRS/Z_H/main.hpp"