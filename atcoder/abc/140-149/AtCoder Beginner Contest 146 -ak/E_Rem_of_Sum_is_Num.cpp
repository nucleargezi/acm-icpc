#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a) std::cin >> x, --x;
    a = pre_sum(a);
    for (ll &x : a) x = (x % k + k) % k;
    map<ll, ll> m{{0, 1}};
    ll ans{};
    for (int i{1}; i < n + 1; ++i) {
        if (i - k > -1) --m[a[i - k]];
        ans += m[a[i]]++;
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