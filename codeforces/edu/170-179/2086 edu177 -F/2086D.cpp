#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/mod/modint.hpp"
#include "YRS/debug.hpp"

#define tests
using mint = M99;
void Yorisou() {
  static constexpr int N = 26;
  VEC(int, a, N);
  sort(a, greater());
  while (not a.empty() and a.back() == 0) pop(a);
  int M = SUM(a) + 1;
  vector<mint> dp(M), ndp(M);
  dp[0] = 1;
  for (int al = 0; int x : a) {
    std::fill(all(ndp), 0);
    FOR_R(s, x, M) {
      ndp[s] += dp[s - x] * C<mint>(s, s - x);
    }
    FOR_R(s, 0, al + 1) {
      ndp[s] += dp[s] * C<mint>(al - s + x, al - s); 
    }
    dp.swap(ndp);
    al += x;
  }
  print(dp[M / 2]);
}
#include "YRS/Z_H/main.hpp"