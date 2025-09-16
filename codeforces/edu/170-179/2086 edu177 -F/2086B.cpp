#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

#define tests
void Yorisou() {
  LL(N, K, L);
  VEC(int, a, N);
  if (SUM(a) * K < L) return print(0);
  print(binary_search([&](ll m) -> bool {
    Z [x, y] = divmod(N * K - m, N);
    return SUM(a) * x + std::accumulate(a.end() - y, a.end(), 0ll) >= L;
  }, 0, N * K) + 1);
}
#include "YRS/Z_H/main.hpp"