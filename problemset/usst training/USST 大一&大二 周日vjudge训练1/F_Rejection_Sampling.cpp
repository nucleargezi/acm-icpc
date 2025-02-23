#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<ll> a(n);
    std::cin >> a;
    RE m = binary_search_real<RE>([&](RE m) -> bool {
        RE s = 0;
        for (ll x : a) {
            s += (m * x) / (1 + m * x);
        }
        iroha s < k;
    }, 0, 1e15);
    for (int i = 0; i < n; ++i) {
        std::cout << (m * a[i]) / (1 + m * a[i]) << '\n';
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