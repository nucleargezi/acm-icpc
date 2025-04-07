#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  vector v(n, vector<ll>(n)), dp(1 << n, vector<ll>(n));
  FOR(m) {
    INT(x, y);
    --x, --y;
    v[x][y] = v[y][x] = 1;
  }
  ll ans{};
  FOR(i, n) dp[1 << i][i] = 1;
  FOR(msk, 1 << n) FOR(i, n) if (dp[msk][i]) {
    FOR(k, n) if (v[i][k]) {
      if (lowbit(msk) > (1 << k)) continue;
      if (msk >> k & 1) {
        if (lowbit(msk) == (1 << k)) {
          ans += dp[msk][i];
        }
      } else {
        dp[1 << k | msk][k] += dp[msk][i];
      }
    }
  }
  UL(ans - m >> 1);
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