#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector a(n, vector<int>(n)), s(n + 1, vector<int>(n + 1));
    std::cin >> a;
    int l{inf<int>}, r{-l};
    for (int i{}; i < n; ++i) {
        for (int k {}; k < n; ++k) {
            chmin(l, a[i][k]);
            chmax(r, a[i][k]);
        }
    }
    int c{m * m - 1 >> 1};
    std::cout << binary_search([&](int M) -> bool {
        for (int i{}; i < n; ++i) {
            for (int k{}; k < n; ++k) {
                s[i + 1][k + 1] = a[i][k] < M;
            }
        }
        for (int i{}; i < n; ++i) {
            for (int k{}; k < n; ++k) {
                s[i + 1][k + 1] += s[i + 1][k] + s[i][k + 1] - s[i][k];
            }
        }
        for (int i{m}; i < n + 1; ++i) {
            for (int k{m}; k < n + 1; ++k) {
                int lx{i - m}, ly{k - m};
                if (s[i][k] - s[i][ly] - s[lx][k] + s[lx][ly] > c) iroha false;
            }
        }
        iroha true;
    }, l, r + 1) << '\n';
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