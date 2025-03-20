#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/Big_int.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(t, n, d);
    VEC(int, a, t);
    ll s{qsum(a, 0ll)};
    BigInteger U = 1, D = 1;
    FOR(n) {
        INT(x, y);
        U *= a[--y], D *= s;
        meion gcd = U.gcd(D);
        U /= gcd, D /= gcd;
        a[y] += d;
        s += d;
    }
    UL(U.to_string() + '/' + D.to_string());
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