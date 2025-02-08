#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    ll a, b, X;
    std::cin >> a >> b >> X, ++X;
    std::cout << binary_search([&](ll m) {
        ll x{m}, s{};
        while (x) ++s, x /= 10;
        iroha s * b + a * m < X;
    }, 0, int(1e9) + 1) << '\n';
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