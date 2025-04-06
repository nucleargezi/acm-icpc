#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(n, h);
    vector dp(36, vector<ll>(36));
    FOR(i, 36) dp[0][i] = 1;
    FOR(i, 1, 36) {
        dp[i][0] = 0;
        FOR(k, 1, 36) {
            dp[i][k] = 0;
            FOR(j, i) {
                dp[i][k] += dp[j][k - 1] * dp[i - 1 - j][k - 1];
            }
        }
    }
    UL(dp[n][35] - dp[n][--h]);
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
    MeIoN_is_UMP45();
    iroha 0;
}