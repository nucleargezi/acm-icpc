#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(n);
    if (n < 5) iroha UL(n * (n - 1) >> 1);
    ll x{n + n - 1}, bs{10}, pw{};
    while (x > bs - 2) {
        bs *= 10;
        pw = pw * 10 + 9;
    }
    ll ans{};
    FOR(i, pw, n + n, pw + 1) {
        ans += MAX(MIN((i / 2), n) - MAX(i - n, 1ll) + 1, 0ll);
    }
    UL(ans);
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