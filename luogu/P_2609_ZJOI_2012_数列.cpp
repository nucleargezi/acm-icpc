#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/Big_int.hpp"

void before() {}

#define tests
using big = BigInteger;
NAME MeIoN_is_UMP45() {
    big n;
    IN(n);
    big l = 1, r = 0;
    while (n > 0) {
        ((n & 1) == 1 ? r : l) = l + r; 
        n >>= 1;
    }
    UL(r);
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