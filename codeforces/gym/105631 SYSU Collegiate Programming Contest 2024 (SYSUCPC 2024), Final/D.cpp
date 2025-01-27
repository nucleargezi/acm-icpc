#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<vector<int>> v(n);
    for (int i{1}, x, y; i < n; ++i) {
        std::cin >> x >> y;
        --x, --y;
        v[x].emplace_back(y), v[y].emplace_back(x);
    }
    vector<ll> sz(n, 1);
    meion passed = [&](meion &&dfs, int n, int fa) -> void {
        for (int i : v[n]) {
            if (i == fa) continue;
            dfs(dfs, i, n);
            sz[n] += sz[i];
        }
    };
    passed(passed, 0, 0);
    vector<ll> ans(n);
    for (int i{1}; i < n; ++i) {
        ans[0] += sz[i] * (sz[i] - 1);
    }
    meion dfs = [&](meion &&dfs, int x, int fa) -> void {
        for (int i : v[x]) {
            if (i == fa) continue;
            ans[i] =
                ans[x] - sz[i] * (sz[i] - 1) + (n - sz[i]) * (n - sz[i] - 1);
            dfs(dfs, i, x);
        }
    };
    dfs(dfs, 0, 0);
    for (ll x : ans) {
        std::cout << x / 2 << '\n';
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