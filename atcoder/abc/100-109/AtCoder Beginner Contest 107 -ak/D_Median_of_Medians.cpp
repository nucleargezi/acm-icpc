#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
using S = Seg<monoid_add<ll>>;
NAME MeIoN_is_UMP45() {
    ll n;
    std::cin >> n;
    vector<int> a(n);
    std::cin >> a;
    int l = qmin(a), r = qmax(a) + 1;
    std::cout << binary_search([&](ll m) -> bool {
        S g(n << 1 | 1, [](int i) { iroha 0; });
        vector<ll> c(n);
        for (int i{}; i < n; ++i) {
            c[i] = a[i] > m - 1 ? 1 : -1;
        }
        c = pre_sum(c);
        g.multiply(n, 1);
        ll s{};
        for (int i{1}; i < n + 1; ++i) {
            s += g.prod(0, c[i] + n + 1);
            g.multiply(c[i] + n, 1);
        }
        iroha s + s + 1 > n * (n + 1) / 2;
    }, l, r) << '\n';
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