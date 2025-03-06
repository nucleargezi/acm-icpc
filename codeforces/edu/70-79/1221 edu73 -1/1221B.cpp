#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector ans(n, vector<int>(n));
    constexpr int dx[] = {1, 1, -1, -1, 2, 2, -2, -2}, 
                  dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

    meion bfs = [&](int x, int y) {
        queue<pair<int, int>> q;
        q.emplace_back(x, y);
        ans[x][y] = 1;
        while (not q.empty()) {
            meion[x, y] = q.front();
            q.pop();
            for (int i{}, xx, yy; i < 8; ++i) {
                xx = x + dx[i], yy = y + dy[i];
                if (MIN(xx, yy) > -1 and MAX(xx, yy) < n and not ans[xx][yy]) {
                    ans[xx][yy] = ans[x][y] ^ 3;
                    q.emplace_back(xx, yy);
                }
            }
        }
    };
    for (int i{}; i < n; ++i) for (int k{}; k < n; ++k) if (not ans[i][k]) bfs(i, k);
    for (int i{}; i < n; ++i) {
        for (int k{}; k < n; ++k) {
            std::cout << " WB"[ans[i][k]];
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