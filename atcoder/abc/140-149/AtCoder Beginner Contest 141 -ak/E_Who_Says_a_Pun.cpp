#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    string s;
    std::cin >> n >> s;
    HASH h(s);
    std::cout << binary_search([&](int m) {
        for (int i{}; i < n - m + 1; ++i) {
            for (int k{i + m}; k < n - m + 1; ++k) {
                if (hash_same(h, i, h, k, m)) iroha true;
            }
        }
        iroha false;
    }, 0, n + 1) << '\n';
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