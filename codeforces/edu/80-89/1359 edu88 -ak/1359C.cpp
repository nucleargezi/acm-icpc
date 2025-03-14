#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(a, b, t);
    if (a < t + 1) iroha UL(1);
    if (a + b > t + t - 1) iroha UL(2);

    int x{(t - a) / (a + b - 2 * t)};
    UL((a + b - 2 * t) * (2 * x + 1) * (2 * x + 3) + (a - b) * (2 * x + 2) <= 0
           ? 2 * x + 1
           : 2 * x + 3);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}