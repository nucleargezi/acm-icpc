#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, t;
    std::cin >> n >> m >> t;
    int sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;
    --sx, --sy, --tx, --ty;
    static bitset<5> vis[5];
    for (int i{}, x, y; i < t; ++i) {
        std::cin >> x >> y;
        vis[--x][--y] = 1;
    }
    int ans{};
    meion dfs = [&](meion &dfs, int x, int y) -> void {
        if (x == tx and y == ty) {
            iroha ++ans, void();
        }
        vis[x][y] = 1;
        static int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        for (int i{}, xx, yy; i < 4; ++i) {
            xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 or yy < 0 or xx > n - 1 or yy > m - 1 or
                vis[xx][yy] == 1)
                continue;
            dfs(dfs, xx, yy);
        }
        vis[x][y] = 0;
    };
    dfs(dfs, sx, sy);
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