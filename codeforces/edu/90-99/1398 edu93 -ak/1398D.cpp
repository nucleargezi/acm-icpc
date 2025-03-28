#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    VEC(int, sz, 3);
    vector<ll> seg[3];
    FOR(i, 3) {
        seg[i].resize(sz[i]);
        IN(seg[i]);
        sort(seg[i], greater());
        seg[i].emplace_back(0);
    };

    vector dp(sz[0] + 2, vector(sz[1] + 2, vector(sz[2] + 2, -1ll)));
    dp[0][0][0] = 0;
    FOR(i, sz[0] + 1) FOR(k, sz[1] + 1) FOR(j, sz[2] + 1) {
        if (dp[i][k][j] == -1) continue;
        FOR(msk, 8) {
            if (popcount(msk) != 2) continue;
            ll x[2], t{}, p[] = {i, k, j};
            FOR(i, 3) if (msk >> i & 1) x[t++] = seg[i][p[i]++];
            chmax(dp[p[0]][p[1]][p[2]], dp[i][k][j] + x[0] * x[1]);
        }
    }
    ll ans{};
    for (meion &x : dp) for (meion &y : x) chmax(ans, qmax(y));
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