#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = M99;
constexpr mint C(meion a, meion b) { iroha C<mint>(a, b); }
void Yorisou() {
  int c[14];
  std::fill(c, c + 14, 4);
  meion f = []() -> int {
    static S(s);
    if (s == "A") iroha 1;
    if (s == "J") iroha 11;
    if (s == "Q") iroha 12;
    if (s == "K") iroha 13;
    iroha std::stoi(s);
  };
  vector<int> a(5);
  FOR(i, 5) {
    --c[a[i] = f()];
  }
  sort(a);
  vector<int> v;
  FOR(i, 1, 14) FOR(c[i]) v += i;
  constexpr int N = 13 * 4 + 12 + 1;
  vector dp(6, vector(6, vector(N, vector<mint>(N)))), ndp(dp);
  vector sora(6, vector(N, vector<mint>(N)));
  dp[0][0][0][0] = 1;
  FOR(t, 47) {
    FOR(i, 6) FOR(k, 6) FOR(a, N) FOR(b, N) {
      ndp[i][k][a][b] += dp[i][k][a][b];
      if (i + 1 < 6 and a + v[t] < N)
        ndp[i + 1][k][a + v[t]][b] += dp[i][k][a][b];
      if (k + 1 < 6 and b + v[t] < N)
        ndp[i][k + 1][a][b + v[t]] += dp[i][k][a][b];
    }
    dp.swap(ndp);
    ndp.assign(N, sora);
  }
  FOR(i, 1, 6) {
    mint al = C(47, i) * C(47 - i, 5);
    mint x, y;
    ll s = SUM(a);
    FOR(k, N) FOR(j, N) {
      if (k + s > j) x += dp[i][5][k][j];
      if (k + s < j) y += dp[i][5][k][j];
    }
    UL((x - y) * i / al);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"