#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(int, a, n);
    VEC(int, p, n);
    INT(m);
    VEC(int, b, m);
    
    lazy_seg<a_monoid_sum_add<i128>> seg(m + 1);
    seg.apply(1, m + 1, inf<ll> / 12);
    FOR(i, n) {
        int x{lower(b, a[i]) - b.begin()};
        if (p[i] < 0) {
            seg.apply(x + 1, m + 1, p[i]);
        }
        if (a[i] == b[x]) {
            ll l{seg.prod(x, x + 1)}, r{seg.prod(x + 1, x + 2)};
            if (l < r) seg.apply(x + 1, x + 2, l - r);
        }
        seg.apply(0, x + 1, p[i]);
    }
    i128 ans{seg.get(m)};
    if (ans > inf<ll> / 24) iroha NO();
    YES();
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}