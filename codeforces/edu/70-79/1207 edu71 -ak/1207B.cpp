#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector v(n + 1, vector<int>(m + 1)), res(v);
    for (int i{}; i < n; ++i) for (int k{}; k < m; ++k) {
        std::cin >> v[i][k];
    }
    
    vector<pair<int, int>> ans;
    constexpr int dx[] = {0, 0, 1, 1}, dy[] = {0, 1, 0, 1};
    for (int i{}; i < n; ++i) for (int k{}; k < m; ++k) {
        if (v[i][k] and v[i + 1][k] and v[i][k + 1] and v[i + 1][k + 1]) {
            ans.emplace_back(i + 1, k + 1);
            for (int x{}; x < 4; ++x) for (int y{}; y < 4; ++y) {
                res[i + dx[x]][k + dy[y]] = 1;
            }
        }
    }
    if (res == v) {
        std::cout << len(ans) << '\n';
        for (meion &x : ans) {
            std::cout << x << '\n';
        }
    } else {
        std::cout << "-1\n";
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