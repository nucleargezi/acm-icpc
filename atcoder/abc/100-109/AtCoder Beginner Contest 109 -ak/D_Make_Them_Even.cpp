#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    int a[n][m];
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            std::cin >> a[i][k];
        }
    }
    int s{};
    vector<tuple<int, int, int, int>> go;
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m - 1; ++k) {
            if (a[i][k] & 1) {
                ++a[i][k + 1];
                --a[i][k];
                ++s;
                go.emplace_back(i + 1, k + 1, i + 1, k + 2);
            }
        }
    }
    for (int i{}; i < n - 1; ++i) {
        if (a[i][m - 1] & 1) {
            ++a[i + 1][m - 1];
            --a[i][m - 1];
            ++s;
            go.emplace_back(i + 1, m, i + 2, m);
        }
    }
    std::cout << s << '\n';
    for (meion x : go) {
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