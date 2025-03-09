#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/min_add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> p(n), a(n);
    std::cin >> p >> a;
    vector<int> pos(n);
    for (int i{}; i < n; ++i) {
        pos[--p[i]] = i;
    }
    lazy_seg<a_monoid_min_add<ll>> seg(n - 1, [](int i) { iroha 0; });
    for (int i{}; i < n; ++i) {
        seg.apply(pos[i], n - 1, a[pos[i]]);
    }
    ll ans{seg.prod_all()};
    for (int i{}; i < n; ++i) {
        seg.apply(0, pos[i], a[pos[i]]);
        seg.apply(pos[i], n - 1, -a[pos[i]]);
        chmin(ans, seg.prod_all());
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