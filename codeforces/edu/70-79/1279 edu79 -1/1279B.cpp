#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    ll n, s;
    std::cin >> n >> s;
    vector<ll> a(n);
    std::cin >> a;
    ll ans{};
    for (ll i{}, max{}, c{}, k{-1}; i < n; ++i) {
        c += a[i];
        if (chmax(max, a[i])) k = i + 1;
        if (c - max < s + 1) ans = k;
    }
    if (qsum(a, 0ll) < s + 1) ans = 0;
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