#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    graph<int> g(n);
    g.read_tree();
    meion d = g.deg_array();
    vector<bool> vis(n); 
    vector<int> dp(n, -inf<int>);
    int ans{-inf<int>};
    meion dfs = [&](meion &dfs, int n, int fa) -> void {
        vector<int> add;
        vis[n] = d[n] > 3;
        if (vis[n]) dp[n] = 1;
        for (meion [f, i, _, __] : g[n]) {
            if (i == fa) continue;
            dfs(dfs, i, n);
            if (vis[i]) {
                add.emplace_back(dp[i]);
            }
        }
        if (vis[n]) {
            sort(add, greater());
            if ((int)add.size() > 4) add.resize(4);
            for (int i {}; i < MIN(int(add.size()), 3); ++i) dp[n] += add[i];
            if ((int)add.size() > 3) chmax(ans, dp[n] + add[3]);
            else chmax(ans, dp[n]);
        }
    };
    dfs(dfs, 0, -1);
    std::cout << (ans == -inf<int> ? -1 : ans * 3 + 2) << '\n';
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