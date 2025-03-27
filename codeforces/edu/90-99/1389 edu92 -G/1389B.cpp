#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(n, k, z);
    VEC(ll, a, n);
    a.resize(k + 1);

    ll ans = qsum(a, 0ll);
    vector dp(z + 1, vector<ll>(k + 1));
    dp[0] = pre_sum<false>(a);
    FOR(i, 1, z + 1) {
        FOR(j, k + 1 - i - i) {
            chmax(dp[i][j], dp[i - 1][j + 1] + a[j]);
            j and chmax(dp[i][j], dp[i][j - 1] + a[j]);
        }
        chmax(ans, qmax(dp[i]));
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