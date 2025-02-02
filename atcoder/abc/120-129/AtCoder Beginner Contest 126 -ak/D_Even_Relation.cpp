#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<vector<pair<int, int>>> v(n);
    for (int i{1}, x, y, w; i < n; ++i) {
        std::cin >> x >> y >> w;
        --x, --y;
        v[x].emplace_back(y, w);
        v[y].emplace_back(x, w);
    }
    vector<int> col(n);
    meion dfs = [&](meion &&dfs, int n, int fa) -> void {
        for (meion [i, w] : v[n]) {
            if (i == fa) continue;
            col[i] = w & 1 ^ col[n];
            dfs(dfs, i, n);
        }
    };
    dfs(dfs, 0, 0);
    for (int x : col) {
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