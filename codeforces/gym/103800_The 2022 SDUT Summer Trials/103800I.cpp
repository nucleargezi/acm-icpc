#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    ll n, m;
    std::cin >> n >> m;
    ll ans{};
    if (m > n * 3) {
        ans = (m - n - 1) / (n << 1);
        m -= ans * (n << 1);
    }
    for (ll i{}, x{1}; x < m; ++i) x *= 3, ++ans;
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