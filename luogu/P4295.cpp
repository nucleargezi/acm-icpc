#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/Big_int.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, d);
    if (n == 1 and d == 1) iroha UL(0);
    if (d == 0) iroha UL(1);
    static BigInteger f[0721];
    f[1] = 1;
    FOR(i, d) {
        BigInteger t = 1;
        FOR(n) t *= f[i];
        f[i + 1] = f[i + 1] + t + 1;
    }
    UL(f[d] - f[d - 1]);
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