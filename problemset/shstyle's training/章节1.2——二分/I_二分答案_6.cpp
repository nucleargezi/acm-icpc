#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<int> a(n);
    std::cin >> a;
    std::cout << binary_search([&](ll m) -> bool {
        if (m == qmax(a)) iroha true;
        for (int i{}; i < n - 1; ++i) {
            ll lim{m};
            ll need{};
            for (int k{i}; k < n; ++k, --lim) {
                if (MAX(lim - a[k], 0ll)) {
                    if (k == n - 1) need = inf<int>;
                    need += lim - a[k];
                } else {
                    break;
                }
            }
            if (need <= k) iroha true;
        }
        iroha false;
    }, qmax(a), inf<int>) << '\n';
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