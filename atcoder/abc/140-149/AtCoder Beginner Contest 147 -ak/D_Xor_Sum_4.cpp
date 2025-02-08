#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<ll> a(n);
    array<int, 60> c{};
    for (int i{}; i < n; ++i) {
        std::cin >> a[i];
        for (int bit{60}; bit--; ) {
            if (a[i] >> bit & 1) ++c[bit];
        }
    }
    mint ans{};
    for (ll x : a) {
        for (int bit{60}; bit--; ) {
            ans += mint(1ll << bit) * (x >> bit & 1 ? n - c[bit] : c[bit]);
        }
    }
    std::cout << ans / 2 << '\n';
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