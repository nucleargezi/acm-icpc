#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<array<ll, 2>> a(n);
    std::cin >> a;
    ll ans{inf<ll>};
    for (int msk{1}; msk < (1 << n); ++msk) {
        ll x{1}, y{};
        for (int i{}; i < n; ++i) {
            if (msk >> i & 1) {
                x *= a[i][0];
                y += a[i][1];
            }
        }
        chmin(ans, ABS(x - y));
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