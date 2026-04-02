#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/mod/modint.hpp"

// #define tests
using mint = M17;
void yorisou(int N, int M, int L, int R) {
  VEC(mint, a, N + 1);
  VEC(mint, b, M + 1);
  a = pre_sum(a);
  mint ans;
  FOR(i, M + 1) {
    int l = std::max(L - i, 0), r = std::min(R - i, N);
    if (l > r) continue;
    ++r;
    ans += b[i] * (a[r] - a[l]);
  }
  print(ans);
}
void Yorisou() {
  int N, M, L, R;
  while (IN(N, M, L, R)) yorisou(N, M, L, R);
}
#include "YRS/Z_H/main.hpp"