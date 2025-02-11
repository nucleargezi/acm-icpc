#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    string s;
    std::cin >> n >> s;
    vector<array<int, 26>> c(n);
    for (int i{}; i < n; ++i) {
        ++c[i][s[i] - 'a'];
    }
    for (int i{1}; i < n; ++i) {
        for (int k{}; k < 26; ++k) {
            c[i][k] += c[i - 1][k];
        }
    }
    int q;
    std::cin >> q;
    for (int i{}; i < q; ++i) {
        array<int, 26> x{};
        string s;
        std::cin >> s;
        for (char c : s) {
            ++x[c - 'a'];
        }
        std::cout << binary_search([&](ll m) {
            for (int i{}; i < 26; ++i) {
                if (x[i] > c[m][i]) iroha false;
            }
            iroha true;
        }, n - 1, -1) + 1 << '\n';
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