#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M17;
void Yorisou() {
  VEC(PII, a, 7);
  int N = 0;
  for (PII &x : a) chmax(N, ++x.se);
  ++N;
  vc<int> I(7);
  iota(all(I), 0);
  mint s;
  do {
    if (min({I[1], I[3], I[5]}) < 4 and max({I[1], I[3], I[5]}) > 2) continue;
    vc<mint> dp(N), ndp(N);
    dp[0] = 1;
    for (Z [l, r] : rearrange(a, argsort(I))) {
      fill(all(ndp), 0);
      mint s = 0;
      FOR(i, N) {
        if (i >= l and i < r) ndp[i] = s;
        s += dp[i];
      }
      dp.swap(ndp);
    }
    s += SUM<mint>(dp);
  } while (next_permutation(all(I)));
  print(s);
}
#include "YRS/aa/main.hpp"