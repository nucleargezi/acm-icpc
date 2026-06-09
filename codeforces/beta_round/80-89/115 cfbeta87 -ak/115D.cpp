#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/binom.hpp"

using mint = mint_t<1'000'000 + 3>;
void Yorisou() {
  STR(s);
  int N = si(s);
  if (not isdigit(s[N - 1])) return print(0);
  retsu<mint> dp(N + 1, N + 1);
  dp[0][0] = 1;
  FOR(i, N) FOR_R(k, N) if (dp[i][k].val()) {
    if (isdigit(s[i])) {
      dp[i + 1][k] += dp[i][k];
    } else if (i == 0 or not isdigit(s[i - 1])) {
      if (s[i] == '+' or s[i] == '-') dp[i + 1][k + 1] += dp[i][k];
      else return print(0);
    } else {
      dp[i + 1][k + 1] += dp[i][k];
      if (k) dp[i][k - 1] += dp[i][k];
    }
  }
  mint rs;
  FOR(i, N) rs += dp[N][i];
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}