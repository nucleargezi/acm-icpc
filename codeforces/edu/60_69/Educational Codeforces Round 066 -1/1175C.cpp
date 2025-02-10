#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, K;
    std::cin >> n >> K;
    vector<int> a(n);
    std::cin >> a;
    sort(a);
    ll ans{};
    binary_search([&](ll m) -> bool {
        for (int i{}, k; i < n - K; ++i) {
            k = i + K;
            if (a[k] - a[i] < m + m + 1) {
                ans = a[i] + a[k] >> 1;
                iroha true;
            }
        }
        iroha false;
    }, inf<ll> >> 10, -1);
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