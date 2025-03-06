#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    queue<pair<int, int>> q;
    q.emplace_back(--x, --y);
    int ans[n][m];
    memset(ans, -1, sizeof ans);
    ans[x][y] = 0;
    while (not q.empty()) {
        meion [x, y] = q.front();
        q.pop();
        static constexpr int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1}, 
                             dy[] = {2, 1, -1, -2, 2, 1, -1, -2};
        for (int i{}, xx, yy; i < 8; ++i) {
            xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 or yy < 0 or xx > n - 1 or yy > m - 1 or ans[xx][yy] != -1) continue;
            ans[xx][yy] = ans[x][y] + 1;
            q.emplace_back(xx, yy);
        }
    }
    for (int i{}; i < n; ++i) {
        for (int k {}; k < m; ++k) {
            std::cout << std::left << std::setw(5) << ans[i][k];
        }
        std::cout << '\n';
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