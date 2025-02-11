#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<vector<int>> v(n);
    for (int i{1}, x, y; i < n; ++i) {
        std::cin >> x >> y, --x, --y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    vector<int> dis(n), fa(n, -1), sz(n);
    [&]() {
        meion dfs = [&](meion &dfs, int n) -> void {
            sz[n] = 1;
            for (int i : v[n]) {
                if (i == fa[n]) continue;
                fa[i] = n;
                dis[i] = dis[n] + 1;
                dfs(dfs, i);
                sz[n] += sz[i];
            }
        };
        dfs(dfs, 0);
    }();
    vector<ll> dp(n);
    for (int i{}; i < n; ++i) dp[0] += ++dis[i];
    [&]() {
        meion dfs = [&](meion &dfs, int n) -> void {
            for (int i : v[n]) {
                if (i == fa[n]) continue;
                dp[i] = dp[n] - sz[i] + (int)v.size() - sz[i];
                dfs(dfs, i);
            }
        };
        dfs(dfs, 0);
    }();
    std::cout << qmax(dp) << '\n';
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