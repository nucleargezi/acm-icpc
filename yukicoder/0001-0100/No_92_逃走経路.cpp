#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M, K);
  VEC(T3<int>, e, M);
  for (Z &[x, y, w] : e) --x, --y;
  vc<u8> dp(N, 1), ndp(N);
  FOR(K) {
    INT(x);
    fill(all(ndp), 0);
    for (Z &&[f, t, w] : e) if (x == w) {
      ndp[f] |= dp[t];
      ndp[t] |= dp[f];
    }
    dp.swap(ndp);
  }
  vc<int> ans;
  FOR(i, N) if (dp[i]) ans.ep(i + 1);
  print(len(ans));
  print(ans);
}
#include "YRS/aa/main.hpp"