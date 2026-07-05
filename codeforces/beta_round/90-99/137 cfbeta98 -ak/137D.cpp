#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  retsu<int> f(N, N + 1);
  FOR_R(l, N) FOR(r, l + 2, N + 1) {
    f[l][r] = f[l + 1][r - 1] + (s[l] != s[r - 1]);
  }

  INT(K);
  retsu<int> dp(N + 1, K + 1, inf<int>), fa(N + 1, K + 1, -1);
  dp[0][0] = 0;
  FOR(i, N) FOR(k, K) if (dp[i][k] != inf<int>) {
    FOR(j, i + 1, N + 1) if (chmin(dp[j][k + 1], dp[i][k] + f[i][j])) {
      fa[j][k + 1] = i;
    }
  }
  int rs = inf<int>, ii;
  FOR(i, K + 1) if (chmin(rs, dp[N][i])) ii = i;
  print(rs);

  rs = N;
  vc<int> pa;
  FOR_R(i, ii + 1) pa.ep(rs), rs = fa[rs][i];
  reverse(pa);
  int sz = si(pa);
  vc<string> out;
  FOR(i, sz - 1) {
    int l = pa[i], r = pa[i + 1];
    FOR(i, r - l) if (s[l + i] != s[r - i - 1]) s[l + i] = s[r - i - 1];
    out.ep(s.substr(l, r - l));
  }
  s = out[0];
  FOR(i, 1, sz - 1) s += '+' + out[i];
  print(s);
}

int main() {
  Yorisou();
  return 0;
}