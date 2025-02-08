#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> in(n);
    vector<vector<pair<int, int>>> v(n);
    for (int i{}, x, y; i < n - 1; ++i) {
        std::cin >> x >> y, --x, --y;
        v[x].emplace_back(y, i);
        v[y].emplace_back(x, i);
        ++in[x], ++in[y];
    }
    int max{qmax(in)};
    std::cout << max << '\n';
    vector<int> ans(n - 1);
    meion dfs = [&](meion &dfs, int n, int fa) -> void {
        set<int> s;
        vector<int> nd;
        for (meion [i, id] : v[n]) {
            if (ans[id]) s.emplace(ans[id]);
            else nd.emplace_back(id);
        }
        for (int i{}; i < max and not nd.empty(); ++i) {
            if (s.contains(i + 1)) continue;
            ans[nd.back()] = i + 1;
            nd.pop_back();
        }
        for (meion [i, id] : v[n]) {
            if (i == fa) continue;
            dfs(dfs, i, n);
        }
    };
    dfs(dfs, 0, 0);
    for (int x : ans) {
        std::cout << x << '\n';
    }
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