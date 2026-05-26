#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using X = array<array<ll, 1 << 6>, 1 << 6>;
void Yorisou() {
  INT(N, M);
  if (N < M) swap(N, M);
  int n = (1 << M) - 1;
  bool f[64][64][64];
  FOR(i, 1 << M) FOR(k, 1 << M) FOR(j, 1 << M) {
    ll c = i | k | j;
    FOR(t, M) if (k >> t & 1) {
      if (t) c |= 1 << (t - 1);
      if (t + 1 < M) c |= 1 << (t + 1);
    }
    f[i][k][j] = c == n;
  }
  X dp, ndp;
  FOR(i, 1 << M) dp[i].fill(inf<ll> / 2);
  dp[n][0] = 0;
  FOR(N) {
    FOR(i, 1 << M) ndp[i].fill(inf<ll> / 2);
    FOR(a, 1 << M) FOR(b, 1 << M) if (dp[a][b] != inf<ll> / 2) {
      FOR(c, 1 << M) if (f[a][b][c]) {
        chmin(ndp[b][c], dp[a][b] + pc(c));
      }
    }
    dp.swap(ndp);
  }
  ll s = inf<ll>;
  FOR(a, 1 << M) FOR(b, 1 << M) if (f[a][b][0]) chmin(s, dp[a][b]);
  print(N * M - s);
}

int main() {
  Yorisou();
  return 0;
}