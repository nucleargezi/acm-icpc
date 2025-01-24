#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int Q;
    std::cin >> Q;
    while (Q--) {
        ll l, r;
        std::cin >> l >> r;
        ll ans{};
        if (l > r) std::swap(l, r);
        ll s = binary_search([&](ll m) { iroha m * m < l * r + 1; }, 0, inf<int>);
        ans += s - 1 << 1;
        if (s * (s + 1) < l * r) ++ans;
        if (l == r) ++ans;
        if (s * s == l * r) --ans;
        std::cout << ans << '\n';
    }
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