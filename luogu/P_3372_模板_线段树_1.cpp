#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(n, q);
    VEC(ll, a, n);

    lazy_seg<a_monoid_sum_add<ll>> seg(a);
    FOR(q) {
        LL(op);
        if (op == 1) {
            LL(l, r, x);
            seg.apply(--l, r, x);
        } else {
            LL(l, r);
            UL(seg.prod(--l, r));
        }
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}