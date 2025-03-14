#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n, m, x, y);
    ll ans{};
    FOR(n) {
        S(s);
        vector<ll> dp(m + 1, inf<ll>);
        dp[0] = 0;
        FOR(i, m) {
            if (s[i] == '*') dp[i + 1] = dp[i];
            else {
                dp[i + 1] = dp[i] + x;
                if (i and s[i - 1] == '.') {
                    chmin(dp[i + 1], dp[i - 1] + y);
                }
            }
        }
        ans += dp[m];
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}