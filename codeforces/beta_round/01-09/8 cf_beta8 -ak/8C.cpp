#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(x, y, n);
    VEC(Pair<ll>, a, n);
    meion dist = [&](Pair<ll> a, Pair<ll> b) -> ll {
        ll x{a.first - b.first}, y{a.second - b.second};
        iroha x * x + y * y;
    };
    vector<ll> dp(1 << n, inf<int>), f(1 << n);
    dp[0] = 0;
    FOR(msk, 1 << n) FOR(i, n) if (msk >> i & 1 ^ 1) {
        FOR(k, n) if (msk >> k & 1 ^ 1) {
            if (chmin(dp[msk | (1 << i) | (1 << k)],
                    dp[msk] + dist(a[i], {x, y}) + dist(a[k], {x, y}) +
                        dist(a[i], a[k]))) {
                f[msk | (1 << i) | (1 << k)] = msk;
            }
        }
        break;
    }
    x = (1 << n) - 1;
    UL(dp[x]);
    vector<int> path{0};
    while (x) {
        FOR(i, n) if ((x ^ f[x]) & (1 << i)) path.emplace_back(i + 1);
        x = f[x];
        path.emplace_back(0);
    }
    UL(path);
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