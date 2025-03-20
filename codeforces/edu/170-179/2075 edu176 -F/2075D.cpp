#include "MeIoN_Lib/MeIoN_all.hpp"

constexpr int N = 62;
vector dp(N, vector<ll>(N, inf<ll>));

void before() {
    dp[0][0] = 0;
    FOR(i, N) {
        FOR_R(k, N) FOR_R(j, N) {
            if (dp[k][j] == inf<ll>) continue;
            chmin(dp[MIN(61ll, k + i)][j], dp[k][j] + (1ll << i));
            chmin(dp[k][MIN(61ll, j + i)], dp[k][j] + (1ll << i));
        }
    }
}

#define tests
NAME MeIoN_is_UMP45() {
    LL(x, y);
    ll ans{inf<ll>};
    FOR(i, N) FOR(k, N) {
        if ((x >> i) == (y >> k)) {
            chmin(ans, dp[i][k]);
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}