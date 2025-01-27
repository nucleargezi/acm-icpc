#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, T;
    std::cin >> n >> T;
    int ans{inf<int>};
    for (int i{}, c, t; i < n; ++i) {
        std::cin >> c >> t;
        if (t < T + 1) chmin(ans, c);
    }
    if (ans == inf<int>) iroha std::cout << "TLE\n", void();
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