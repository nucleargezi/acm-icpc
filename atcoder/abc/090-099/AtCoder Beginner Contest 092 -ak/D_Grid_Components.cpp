#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int a, b;
    std::cin >> a >> b;
    static constexpr int n = 100;
    char ans[n][n];
    for (int i{}; i < n; ++i) {
        for (int k{}; k < n; ++k) {
            ans[i][k] = (i < n / 2 ? '#' : '.');
        }
    }
    --a, --b;
    for (int i{1}; i < n / 2 and a; i += 2) {
        for (int k{1}; k < n and a; k += 2) {
            ans[i][k] = '.';
            --a;
        }
    }
    for (int i{n / 2 + 1}; i < n and b; i += 2) {
        for (int k{1}; k < n and b; k += 2) {
            ans[i][k] = '#';
            --b;
        }
    }
    std::cout << "100 100\n";
    for (int i{}; i < n; ++i) {
        for (int k{}; k < n; ++k) {
            std::cout << ans[i][k];
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