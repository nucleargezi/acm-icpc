#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int l, r;
    std::cin >> l >> r;
    ll ans = inf<ll>;
    for (int i = l; i < std::min(l + 2019, r + 1); ++i) {
        for (int k = i + 1; k < std::min(l + 2019, r + 1); ++k) {
            chmin(ans, (1ll * i * k) % 2019);
        }
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