#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    static constexpr int N = 100;
    static bitset<N> v[N], vv[N];
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            char c;
            std::cin >> c;
            v[i][k] = c == 'W';
        }
    }
    meion dfs = [&](meion &dfs, int x, int y) -> void {
        if (vv[x][y] or not v[x][y]) iroha;
        vv[x][y] = 1;
        static constexpr int dx[] = {0, 0, 1, -1, -1, -1, 1, 1}, 
                             dy[] = {-1, 1, 0, 0, 1, -1, 1, -1};
        for (int i{}, xx, yy; i < 8; ++i) {
            xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 or yy < 0 or xx > n - 1 or yy > m - 1)
                continue;
            dfs(dfs, xx, yy);
        }
    };
    int ans{};
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            if (v[i][k] and not vv[i][k]) ++ans;
            dfs(dfs, i, k);
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