#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/Big_int.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    using big = BigInteger;
    big m;
    IN(m);
    if (m == 5) iroha UL(3);
    big n = 1, ans = 0;
    int len = 1;
    for (; n < m; len++, n = n * 2 + 1) {
        ans += big(1) << (len - 1) / 2;
    }
    ans += (m & (n >> 1)) >> (len / 2);
    int l = len / 2, r = len - l - 1;
    while (l < len and r > -1) {
        if (((m >> l) & 1) < ((m >> r) & 1)) iroha UL(ans + 1);
        if (((m >> l) & 1) > ((m >> r) & 1)) iroha UL(ans);
        ++l, --r;
    }
    UL(ans + 1);
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