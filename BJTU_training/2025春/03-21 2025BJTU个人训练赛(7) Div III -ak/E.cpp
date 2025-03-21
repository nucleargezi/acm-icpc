#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    vector<pair<int, int>> a(m);
    for (meion &[x, y] : a) {
        int sz;
        IN(x, sz);
        FOR(sz) {
            INT(x);
            y |= 1 << --x;
        }
    }
    vector<int> dp(1 << n, inf<int>);
    dp[0] = 0;
    FOR(i, 1 << n) {
        if (dp[i] == inf<int>) continue;
        for (meion [x, y] : a) {
            chmin(dp[i | y], dp[i] + x);
        }
    }
    UL(dp.back() == inf<int> ? -1 : dp.back());
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