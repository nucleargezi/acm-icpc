#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, q;
    std::cin >> n >> q;
    vector<vector<int>> v(n);
    for (int i{1}, x, y; i < n; ++i) {
        std::cin >> x >> y, --x, --y;
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }

    vector<int> ans(n);
    for (int i{}, p, x; i < q; ++i) {
        std::cin >> p >> x;
        ans[--p] += x;
    }
    
    meion dfs = [&](meion &&dfs, int n, int fa) -> void {
        for (int i : v[n]) {
            if (i == fa) continue;
            ans[i] += ans[n];
            dfs(dfs, i, n);
        }
    };
    dfs(dfs, 0, 0);
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