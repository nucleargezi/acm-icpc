#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n, p, k);
    VEC(int, a, n);
    sort(a);
    vector<int> dp(n + 1);
    FOR(i, n) {
        dp[i + 1] = i < k - 1 ? 
            dp[i] + a[i] : 
            MIN(dp[i] + a[i], dp[i - k + 1] + a[i]);
    }
    FOR_R(i, 0, n + 1) if (dp[i] < p + 1) iroha UL(i);
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