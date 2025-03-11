#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(ll, a, n);
    a.insert(a.end(), a.begin(), a.end());
    vector dp(n << 1, vector<ll>(n << 1));
    FOR_R(l, n + n) {
        FOR(r, l, n + n) {
            if (r - l + 1 > n) break;
            FOR_R(m, l, r){
                chmax(dp[l][r], dp[l][m] + dp[m + 1][r]);
            }
            FOR(m, l + 1, r) {
                chmax(dp[l][r],
                      dp[l + 1][m - 1] + dp[m + 1][r - 1] + a[l] * a[r] * a[m]);
            }
        }
    }
    ll ans{};
    for (meion &x : dp) chmax(ans, qmax(x));
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