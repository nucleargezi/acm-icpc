#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, mod);
  vector<ll> pow(50);
  pow[0] = 1;
  FOR(i, 1, 50) {
    pow[i] = pow[i - 1] * 10 % mod;
  }
  ll a[n][n];
  FOR(i, n) FOR(k, n) {
    IN(a[i][k]);
    a[i][k] *= pow[n + n - i - k - 2];
    a[i][k] %= mod;
  }
  if (n == 1) iroha UL(a[0][0]);

  set<ll> dp[n][n], pd[n][n];
  dp[0][0].emplace(a[0][0]);
  FOR(i, n) FOR(k, n) {
    if (not i and not k) continue;
    if (i + k > n - 1) break;
    FOR(e, 2) FOR(f, 2) if (e ^ f and MIN(i - e, k - f) > -1) {
      for (ll x : dp[i - e][k - f]) {
        dp[i][k].emplace((x + a[i][k]) % mod);
      }
    }
  }
  pd[n - 1][n - 1].emplace(a[n - 1][n - 1]);
  ll ans{};
  FOR_R(i, n) FOR_R(k, n) {
    if (n - i + n - k > n) break;
    if (not(i + 1 == n and k + 1 == n)) {
      FOR(e, 2) FOR(f, 2) if (e ^ f and MAX(i + e, k + f) < n) {
        for (ll x : pd[i + e][k + f]) {
          pd[i][k].emplace((x + a[i][k]) % mod);
        }
      }
    }
    if (n - i + n - k == n) {
      FOR(e, 2) FOR(f, 2) if (e ^ f and MIN(i - e, k - f) > -1) {
        for (ll x : pd[i][k]) {
          meion it = dp[i - e][k - f].lower_bound(mod - x);
          if (it != dp[i - e][k - f].begin()) {
            chmax(ans, x + *std::prev(it));
          }
        }
        chmax(ans, (*pd[i][k].rbegin() + *dp[i - 1][k].rbegin()) % mod);
      }
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