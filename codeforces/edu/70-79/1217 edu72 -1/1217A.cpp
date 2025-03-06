#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int a, b, s;
    std::cin >> a >> b >> s;
    int x{binary_search([&](ll m) -> bool {
        if (m == s + 1) iroha true;
        iroha a + m > b + s - m;
    }, s + 1, -1)};
    std::cout << ((x == s + 1) ? 0 : s - x + 1) << '\n';
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