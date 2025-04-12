#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<51123987>;
void Yorisou() {
  INT(n);
  SV(a, 'a');
  int N{ceil(n, 3)};
  vector dp(3, vector(N + 1, vector(N + 1, vector<mint>(N + 1))));
  for (int x : a) {
    vector ndp(N + 1, vector(N + 1, vector<mint>(N + 1)));
    int a{x == 0}, b{x == 1}, c{x == 2};
    ndp[a][b][c] = 1;
    FOR(i, N + 1 - a) FOR(k, N + 1 - b) FOR(j, N + 1 - c) {
      ndp[i + a][k + b][j + c] += dp[(x + 1) % 3][i][k][j] + dp[(x + 2) % 3][i][k][j];
    }
    FOR(i, N + 1 - a) FOR(k, N + 1 - b) FOR(j, N + 1 - c) {
      ndp[i + a][k + b][j + c] += ndp[i][k][j];
    }
    dp[x].swap(ndp);
  }
  mint ans{};
  FOR(i, N + 1) FOR(k, N + 1) {
    ll j{n - i - k};
    if (MAX(i, k, j) - MIN(i, k, j) < 2) {
      FOR(l, 3) ans += dp[l][i][k][j];
    }
  }
  UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}