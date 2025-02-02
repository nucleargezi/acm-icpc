#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    ll ans{};
    for (int i{1}; i < n - 1; ++i) {
        ll t{};
        for (int k {}; k < (n - 1) / i; ++k) {
            if (not((n - 1) % i) and not(i * k < n - 1 - i * k)) break;
            t += a[i * k] + a[n - 1-  i * k];
            chmax(ans, t);
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