#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(m, d, w);
    ll min{MIN(m, d)};
    --d;
    ll gcd{GCD(d, w)};
    d /= gcd, w /= gcd;
    ll x{(min - 1) / w};
    UL(min * x - (1 + x) * x / 2 * w);
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