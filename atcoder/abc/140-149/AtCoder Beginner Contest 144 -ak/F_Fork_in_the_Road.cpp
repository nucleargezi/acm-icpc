#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> v(n), g(n);
    for (int i{}, x, y; i < m; ++i) {
        std::cin >> x >> y, --x, --y;
        v[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    using RE = long double;
    vector<RE> dp(n);
    for (int i{n - 1}; i--; ) {
        for (int x : v[i]) {
            dp[i] += (dp[x] + 1) / (int)v[i].size();
        }
    }
    vector<RE> pd(n);
    pd[0] = 1;
    for (int i{1}; i < n; ++i) {
        for (int x : g[i]) {
            pd[i] += pd[x] / (int)v[x].size();
        }
    }
    RE ans{dp[0]};
    for (int i{}; i < n - 1; ++i) {
        if (v[i].size() == 1) continue;
        for (int x : v[i]) {
            chmin(ans,
                  dp[0] +
                      pd[i] * (dp[i] * int(v[i].size()) / int(v[i].size() - 1) -
                               (dp[x] + 1) / int(v[i].size() - 1) - dp[i]));
        }
    }
    std::cout << ans << '\n';
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