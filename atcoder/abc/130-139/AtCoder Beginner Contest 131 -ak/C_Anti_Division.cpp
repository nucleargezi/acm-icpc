#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    ll l, r, x, y;
    std::cin >> l >> r >> x >> y;
    meion go = [&](ll q) -> ll {
        if (x == 1 or y == 1) iroha 0;
        set<ll> s;
        ll lcm = LCM(x, y);
        iroha q - q / x - q / y + q / lcm;
    };
    std::cout << go(r) - go(--l) << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}