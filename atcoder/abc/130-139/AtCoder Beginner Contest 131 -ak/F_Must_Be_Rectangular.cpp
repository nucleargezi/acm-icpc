#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    static constexpr int bas = 1'000'00;
    dsu g(bas << 1);
    for (int i{}, x, y; i < n; ++i) {
        std::cin >> x >> y;
        --x, --y;
        g.merge(x, y + bas);
    }
    vector<int> a(bas << 1), b(a);
    for (int i{}; i < bas; ++i) {
        ++a[g[i]], ++b[g[i + bas]];
    }
    ll ans{-n};
    for (int i{}; i < bas + bas; ++i) {
        ans += 1ll * a[i] * b[i];
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