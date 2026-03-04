#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/mod/binom.hpp"

using mint = mint_t<1'000'000'009>;
constexpr int sz = 2000;
vc<mint> f() {
  STR(s);
  vc<mint> dp(sz);
  int N = len(s), sum = 0;
  FOR(i, N) {
    int x = s[i] - '0';
    vc<mint> ndp(sz);
    FOR(i, x) ndp[sum + i] += 1;
    FOR(i, sz) if (dp[i].val()) {
      FOR(k, 10) ndp[i + k] += dp[i];
    }
    dp.swap(ndp);
    sum += x;
  }
  dp[sum] += 1;
  return dp;
}
void Yorisou() {
  vc<mint> a = f(), b = f();
  mint s;
  FOR(i, 1, sz) s += a[i] * b[i];
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"