#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, a, b);
    VEC(ll, v, n);
    v.insert(v.begin(), 0);
    vector c = pre_sum<false>(v);

    ll dp[n + 1][a + 1][2];
    std::fill(&dp[0][0][0], &dp[0][0][(n + 1) * (a + 1) * 2], inf<ll>);
    dp[0][0][0] = dp[0][0][1] = 0;
    FOR(i, n) FOR(k, a + 1) FOR(L, 2) FOR(R, 2) if (dp[i][k][L] != inf<ll>) {
        not L and not R and a + 1 > k + v[i + 1] and
            chmin(dp[i + 1][k + v[i + 1]][R], dp[i][k][L]);
        L and R and b + 1 > c[i] - k + v[i + 1] and
            chmin(dp[i + 1][k][R], dp[i][k][L]);
        not L and R and b + 1 > c[i] - k + v[i + 1] and
            chmin(dp[i + 1][k][R], dp[i][k][L] + MIN(v[i + 1], v[i]));
        L and not R and a + 1 > k + v[i + 1] and
            chmin(dp[i + 1][k + v[i + 1]][R], dp[i][k][L] + MIN(v[i + 1], v[i]));
    }

    ll s{c[n]}, ans{inf<ll>};
    FOR(i, a + 1) if (s - i < b + 1) {
        chmin(ans, MIN(dp[n][i][0], dp[n][i][1]));
    }
    UL(ans == inf<ll> ? -1 : ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}