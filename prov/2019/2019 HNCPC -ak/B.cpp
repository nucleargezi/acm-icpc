#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/bigint/big.hpp"

// #define tests
using G = bigint;
int N, K;
G A(int l, int r) {
  G t = 1;
  FOR(i, l, r + 1) t *= i;
  return t;
}
void yorisou() {
  G ans = 1'000'000'000'000'000'000;
  if (N - K < 100) chmin(ans, A(K + 1, N) / A(1, N - K));
  if (K < 100) chmin(ans, A(N - K + 1, N) / A(1, K));
  print(ans);
}
void Yorisou() {
  while (IN(N, K)) yorisou();
}
#include "YRS/Z_H/main.hpp"