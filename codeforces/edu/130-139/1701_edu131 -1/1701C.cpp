#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> s(n);
    for (int i{}, x; i < m; ++i) {
        std::cin >> x;
        ++s[--x];
    }
    std::cout << binary_search([&](int m) -> bool {
        ll c{};
        for (int x : s) {
            if (x < m + 1) c += m - x >> 1;
            else c -= x - m;
        }
        iroha c >= 0;
    }, m << 1, 0) << '\n';
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