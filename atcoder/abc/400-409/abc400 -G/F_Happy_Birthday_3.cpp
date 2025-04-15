#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  VEC(ll, a, n);
  VEC(ll, b, n);
  FOR(i, n) --a[i];
  a += a;
  const int N = n << 1 | 1;
  constexpr ll INF = inf<ll> >> 2;
  ll dp[N][N], t[N][N];
  std::fill(dp[0], dp[0] + (N * N), INF);
  std::fill(t[0], t[0] + (N * N), INF);
  FOR(i, N) dp[i][i] = 0;
  FOR(i, N) t[i][i] = 0;
  FOR_R(l, N) {
    FOR(r, l + 1, N) {
      FOR(m, l + 1, r) {
        chmin(dp[l][r], dp[l][m] + dp[m][r]);
        chmin(t[l][r], t[l][m] + dp[m][r]);
      }
      if (a[l] == a[r - 1]) {
        chmin(t[l][r], t[l][r - 1]);
        chmin(dp[l][r], t[l][r] + r - l + b[a[l]]);
      }
    }
  }
  ll ans{INF};
  FOR(i, n) chmin(ans, dp[i][i + n]);
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