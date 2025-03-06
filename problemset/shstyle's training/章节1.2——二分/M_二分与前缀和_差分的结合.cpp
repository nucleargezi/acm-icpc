#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/min_add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<ll> a(n);
    std::cin >> a;
    lazy_seg<a_monoid_min_add<ll>> seg(a);
    for (int i{}, d, s, t; i < m; ++i) {
        std::cin >> d >> s >> t;
        seg.apply(--s, t, -d);
        if (seg.prod(s, t) < 0) {
            iroha std::cout << "-1\n" << i + 1 << '\n', void();
        }
    }
    std::cout << 0 << '\n';
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