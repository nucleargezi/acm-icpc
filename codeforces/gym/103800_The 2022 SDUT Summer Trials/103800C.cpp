#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, mod;
    std::cin >> n >> mod;
    vector<ll> a(n);
    std::cin >> a;
    if (n < 18) {
        bool f{};
        vector<int> c(mod);
        for (int msk{}; msk < (1 << n) and not f; ++msk) {
            ll s{};
            for (int i{}; i < n; ++i) {
                if (msk >> i & 1) s += a[i];
            }
            ++c[s % mod];
        }
        YES(qmax(c) > 1);
    } else {
        YES();
    }
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