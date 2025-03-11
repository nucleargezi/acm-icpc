#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(x);
    for (ll i{60}, y(x); i--; ) {
        if (x >> i & 1) {
            y ^= 1ll << i;
            y |= (1ll << i) - 1;
            vector<ll> a{x, y, x ^ y};
            sort(a);
            if (a[0] + a[1] > a[2]) iroha UL(y);
        }
    }
    UL(-1);
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