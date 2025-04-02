#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(a, b, c, r);
    if (a > b) std::swap(a, b);
    ll L{MAX(a, c - r)}, R{MIN(b, c + r)};
    if (L > b - 1 or R < a + 1) iroha UL(b - a);
    UL(L - a + b - R);
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