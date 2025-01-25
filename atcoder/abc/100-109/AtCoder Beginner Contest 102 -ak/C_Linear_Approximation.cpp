#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<ll> a(n);
    for (int i{}; i < n; ++i) {
        std::cin >> a[i];
        a[i] -= i + 1;
    }
    sort(a);
    ll s{qsum(a, 0ll)}, ss{};
    ll ans{inf<ll>};
    for (int i{}; i < n; ++i) {
        s -= a[i];
        chmin(ans, a[i] * i - ss + s - a[i] * (n - i - 1));
        ss += a[i];
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