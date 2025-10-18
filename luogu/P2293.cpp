#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/Big_int.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    using big = BigInteger;
    INT(POW);
    big to;
    IN(to);

    if (POW == 1 or to == 0) iroha UL(to);

    big l = 1, r = big(10).pow(1000) + 2;
    while (r - l > 1) {
        big m = l + r >> 1;
        (m.pow(POW) <= to ? l : r) = m;
    }
    UL(l);
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