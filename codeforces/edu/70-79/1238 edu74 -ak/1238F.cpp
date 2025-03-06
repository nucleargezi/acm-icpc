#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    graph<int> g(n);
    g.read_tree();
    tree v(g);
    meion in(g.deg_array());
    int ans{};
    vector<int> dp(n);
    for (int n : std::views::reverse(v.V)) {
        int len{in[n] - 1};
        dp[n] = len;
        for (meion [a, i, b, c] : g[n]) {
            if (i == v.fa[n]) continue;
            chmax(ans, dp[n] + dp[i]);
            chmax(dp[n], len + dp[i]);
        }
    }
    std::cout << ans + 2 << '\n';
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