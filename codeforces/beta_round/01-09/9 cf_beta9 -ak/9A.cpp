#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(a, b);
    ll max{MAX(a, b) - 1};
    if (not max) iroha UL("1/1");
    if (max % 2 == 0)
        std::cout << std::format("{}/3\n", 3 - max / 2);
    else if (max == 3)
        std::cout << std::format("1/2\n");
    else if (max == 5)
        std::cout << std::format("1/6\n");
    else
        std::cout << std::format("{}/6\n", 6 - max);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}