#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    ll l, r;
    std::cin >> l >> r, --l;
    meion go = [](ll n) -> ll {
        ll mod{n & 3};
        if (mod == 0) iroha n;
        if (mod == 1) iroha 1;
        if (mod == 2) iroha n + 1;
        iroha 0;
    };
    std::cout << (go(l) ^ go(r)) << '\n';
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