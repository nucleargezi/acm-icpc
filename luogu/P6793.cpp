#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam_ex.hpp"

void Yorisou() {
  INT(N, K);
  STR(s, t);
  for (char &c : s) c -= 'a';
  for (char &c : t) c -= 'a';
  reverse(s);
  reverse(t);
  
  sam_ex ss;
  vc<array<int, 2>> dp(N << 2);
  int x = 0;
  FOR(i, N) {
    x = ss.add(x, s[i]);
    if (i >= K - 1) ++dp[x][0];
  }
  x = 0;
  FOR(i, N) {
    x = ss.add(x, t[i]);
    if (i >= K - 1) ++dp[x][1];
  }
  vc<vc<int>> g(ss.build_dir_g());

  ll rs = 0;
  Z f = [&](Z &f, int n) -> void {
    for (int x : g[n]) f(f, x), dp[n][0] += dp[x][0], dp[n][1] += dp[x][1];
    int lcp = min(ss[n].sz, K), d = min(dp[n][0], dp[n][1]);
    rs += ll(K - lcp) * d;
    FOR(i, 2) dp[n][i] -= d;
  };
  f(f, 0);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}