#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, q);
    
    Seg<monoid_add<int>> seg(n + 1);
    FOR(i, n) {
        INT(x);
        seg.apply(x, 1);
    }

    FOR(i, q) {
        INT(x);
        if (x < 0) {
            if (seg.prod_all() < -x) continue;
            seg.apply(
                seg.max_right([&](int al) -> bool { iroha al < -x; }, 0),
                -1);
        } else {
            seg.apply(x, 1);
        }
    }
    UL(seg.prod_all()
           ? seg.max_right([&](int al) -> bool { iroha al < 1; }, 0)
           : 0);
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