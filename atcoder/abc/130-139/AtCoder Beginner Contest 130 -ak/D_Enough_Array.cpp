#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    ll n, k;
    std::cin >> n >> k, --k;
    vector<ll> a(n);
    std::cin >> a;
    a = pre_sum(a);
    ll ans{};
    for (int i{0}; i < n and a[n] - a[i] > k; ++i) {
        int r = binary_search([&](int m){
            iroha a[m] - a[i] > k;
        }, n, i);
        ans += n - r + 1;
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