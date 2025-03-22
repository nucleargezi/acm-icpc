#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, L);
    VEC(ll, a, n);

    vector<ll> dp(n + 1);
    vector c = pre_sum(a);
    meion sqr = [](ll x) -> ll { iroha x * x; };
    FOR(i, 1, n + 1) {
        dp[i] = inf<ll>;
        FOR(k, MAX(0ll, i - 500), i) {
            chmin(dp[i], dp[k] + sqr(L - (i - k - 1 + c[i] - c[k])));
        }
    }
    UL(dp[n]);
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