#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/euler_phi.hpp"

void before() {}

// #define tests

using mint = modint<666623333>;
NAME MeIoN_is_UMP45() {
    ll l, r;
    std::cin >> l >> r;
    meion v = euler_phi_table2(l, ++r);
    mint ans{};
    for (int i{}; ll x : v) {
        ans += l - x + i++;
    }
    std::cout << ans << '\n';
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