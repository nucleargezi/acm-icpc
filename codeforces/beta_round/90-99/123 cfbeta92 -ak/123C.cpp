#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

constexpr ll in = inf<ll> / 4;
void Yorisou() {
  LL(N, M, K);
  int sz = N + M - 1;
  vc<int> pr(sz, inf<int>);
  FOR(i, N) FOR(k, M) {
    INT(x);
    chmin(pr[i + k], x);
  }
  retsu<ll> dp(sz + 1, sz + 2);
  string s(sz, '?');
  Z ke = [&]() {
    dp.fill(0);
    dp[0][0] = 1;
    FOR(i, sz) FOR(k, sz + 1) if (dp[i][k] > 0) {
      if (s[i] != ')') {
        dp[i + 1][k + 1] = min(dp[i + 1][k + 1] + dp[i][k], in);
      }
      if (s[i] != '(' and k) {
        dp[i + 1][k - 1] = min(dp[i + 1][k - 1] + dp[i][k], in);
      }
    }
    return dp[sz][0];
  };
  for (int x : argsort(pr)) {
    s[x] = '(';
    ll d = ke();
    if (d < K) K -= d, s[x] = ')';
  }
  FOR(i, N) print(s.substr(i, M));
}

int main() {
  Yorisou();
  return 0;
}