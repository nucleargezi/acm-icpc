#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint.hpp"

#define tests
using mint = M17;
int T;
void Yorisou() {
  cout << std::format("Case {}: ", ++T);
  INT(N, M, K, P, X);
  vector<int> pw(K + 1, 1);
  FOR(i, 1, K + 1) pw[i] = pw[i - 1] * 10;
  VEC(T3<int>, e, M);
  for (Z &[x, y, w] : e) --x, --y;

  int ls = K / 2, rs = K - ls;
  vector dp(N, vector<mint>(1, 1)), ddp(dp);
  FOR(i, ls) {
    vector ndp(N, vector<mint>(std::min(pw[i + 1], P)));
    for (Z [x, y, w] : e) {
      FOR(v, std::min(pw[i], P)) {
        ndp[y][(v * 10 + w) % P] += dp[x][v];
      }
    }
    dp.swap(ndp);
  }
  FOR(i, rs) {
    vector ndp(N, vector<mint>(std::min(pw[i + 1], P)));
    for (Z [x, y, w] : e) {
      FOR(v, std::min(pw[i], P)) {
        ndp[x][(v + w * pw[i]) % P] += ddp[y][v];
      }
    }
    ddp.swap(ndp);
  }
  mint ans;
  FOR(i, N) FOR(v, std::min(pw[ls], P)) {
    int o = (X - v * pw[K - ls] % P + P) % P;
    if (o < pw[K - ls]) ans += dp[i][v] * ddp[i][o];
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"