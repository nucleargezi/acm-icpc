#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<RE> dp(1 << n);
    dp[0] = 1;
    for (int msk{}; msk < (1 << n) - 1; ++msk) {
        int s{popcount(msk)};
        if (not(s < m or msk >> s & 1)) {
            dp[1 << s | msk] += dp[msk];
            continue;
        }
        for (int bit{}; bit < n; ++bit) {
            if (msk >> bit & 1) continue;
            dp[1 << bit | msk] += dp[msk] * (1.L / (n - s));
        }
    }
    dp.resize(1 << --n);
    std::cout << dp.back() << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}