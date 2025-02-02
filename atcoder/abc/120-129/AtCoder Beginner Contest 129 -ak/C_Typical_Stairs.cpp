#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    mint dp[n + 1];
    bool vis[n + 1];
    memset(vis, 0, sizeof vis);
    for (int i{}, x; i < m; ++i) {
        std::cin >> x;
        vis[x] = 1;
    }
    dp[0] = 1;
    for (int i{1}; i < n + 1; ++i) {
        if (vis[i]) continue;
        if (i > 0 and not vis[i - 1]) {
            dp[i] += dp[i - 1];
        }
        if (i > 1 and not vis[i - 2]) {
            dp[i] += dp[i - 2];
        }
    }
    std::cout << dp[n] << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}