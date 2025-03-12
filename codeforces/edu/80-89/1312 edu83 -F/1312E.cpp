#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(int, a, n);
    vector dp(n, vector<int>(n, inf<int>)), x(dp);
    FOR(i, n) {
        dp[i][i] = 1;
        x[i][i] = a[i];
    }
    FOR(d, 1, n) FOR(l, n - d) FOR(m, l, l + d) {
        chmin(dp[l][l + d], dp[l][m] + dp[m + 1][l + d]);
        if (dp[l][m] == 1 and dp[m + 1][l + d] == 1 and
            x[l][m] == x[m + 1][l + d]) {
            dp[l][l + d] = 1;
            x[l][l + d] = x[l][m] + 1;
        }
    }
    UL(dp[0][--n]);
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