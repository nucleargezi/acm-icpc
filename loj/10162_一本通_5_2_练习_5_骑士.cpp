#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/unicycle_forest.hpp"

void Yorisou() {
  INT(N);
  vl a(N);
  vc<PII> e(N);
  FOR(i, N) {
    INT(x, f);
    --f;
    a[i] = x;
    e[i] = {f, i};
  }
  Z [C, vs, es, fa, fe, rs, g] = unicycle_forest(N, e);
  vc<array<ll, 2>> dp(N);
  Z f = [&](Z &f, int n) -> void {
    dp[n][1] = a[n];
    for (var [x, ei] : g[n]) {
      f(f, x);
      dp[n][1] += dp[x][0];
      dp[n][0] += max(dp[x][0], dp[x][1]);
    }
  };
  FOR(i, C) for (int n : vs[i]) f(f, n);

  Z fdp = dp;
  ll al = 0, in = -inf<ll> / 2;
  
  for (var vs : vs) {
    ll s = 0;
    int sz = si(vs);
    dp[vs[0]][0] = in;
    FOR(i, 1, sz) {
      int f = vs[i - 1], t = vs[i];  
      dp[t][0] += max(dp[f][0], dp[f][1]);
      dp[t][1] += dp[f][0];
    }
    chmax(s, dp[vs.back()][0]);
  
    for (int x : vs) dp[x] = fdp[x];
    dp[vs[0]][1] = in;
    FOR(i, 1, sz) {
      int f = vs[i - 1], t = vs[i];  
      dp[t][0] += max(dp[f][0], dp[f][1]);
      dp[t][1] += dp[f][0];
    }
    chmax(s, dp[vs.back()][0]);
    chmax(s, dp[vs.back()][1]);
    al += s;
  }
  print(al);
}

int main() {
  Yorisou();
  return 0;
}