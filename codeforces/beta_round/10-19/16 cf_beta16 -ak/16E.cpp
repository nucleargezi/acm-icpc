#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
void Yorisou() {
  INT(n);
  VVEC(RE, v, n, n);
  const int N{1 << n};
  RE dp[N]{};
  dp[N - 1] = 1;
  FOR_R(msk, 0, N) {
    int c{popcount(msk)};
    FOR(i, n) if (msk >> i & 1) {
      int t{1 << i ^ msk};
      FOR(k, n) if (i != k and (msk >> k & 1)) {
        dp[t] += dp[msk] * v[k][i] / ((c - 1) * c / 2);
      }
    }
  }
  vector<RE> ans;
  FOR(i, n) ans += dp[1 << i];
  UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(6);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}