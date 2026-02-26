#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  vc<int> a(N);
  FOR(i, N) {
    STR(s);
    FOR(k, N) s[k] -= '0';
    FOR(k, N) a[i] |= int(s[k]) << k;
  }
  vc<int> ans(N);
  --N;
  vc<int> dp(1 << N);
  FOR(i, N) if (a[N] >> i & 1) dp[1 << i] |= 1 << i;
  FOR(s, 1 << N) {
    for (int x = (1 << N) - 1 - s; x; x -= x & -x) {
      int t = s | (x & -x);
      if (dp[s] & a[lowbit(x)]) dp[t] |= x & -x;
    }
  }
  FOR(i, N) if (dp.back() >> i & 1) {
    ans[N] |= 1 << i;
    ans[i] |= 1 << N;
  }
  FOR(s, 1 << N) {
    for (int x = dp[s]; x; x -= x & -x) {
      ans[lowbit(x)] |= dp[(1 << N) - 1 - s];
    }
  }
  FOR(i, N + 1) {
    string s(N + 1, '0');
    FOR(k, N + 1) if (ans[i] >> k & 1) ++s[k];
    print(s);
  }
}
#include "YRS/aa/main.hpp"