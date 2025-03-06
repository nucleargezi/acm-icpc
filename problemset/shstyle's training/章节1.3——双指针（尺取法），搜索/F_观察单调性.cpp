#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, k;
    std::cin >> n >> m >> k;
    int a[n][m];
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            std::cin >> a[i][k];
        }
    }
    vector<int> c(k), ans;
    std::cin >> c;
    for (int i : c) {
        int x{}, y{--i};
        while (x < n) {
            if (a[x][y] == 1) {
                a[x][y] = 2;
                ++y;
            } else if (a[x][y] == 2) {
                ++x;
            } else {
                a[x][y] = 2;
                --y;
            }
        }
        ans.emplace_back(++y);
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