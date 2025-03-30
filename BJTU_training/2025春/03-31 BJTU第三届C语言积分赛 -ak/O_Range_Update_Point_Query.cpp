#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/max_idx.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, q);
    VEC(int, a, n);
    Seg<monoid_max_idx<int>> seg(n, [&](int i) { iroha pair {a[i], i}; });
    meion f = [](int x) {
        int res {};
        while (x) {
            res += x % 10;
            x /= 10;
        }
        iroha res;
    };
    FOR(q) {
        INT(op);
        if (op == 1) {
            INT(l, r);
            --l;
            vector<pair<int, int>> upd;
            while (true) {
                meion[max, idx] = seg.prod(l, r);
                if (max > 9) {
                    seg.set(idx, {0, idx});
                    upd.emplace_back(max, idx);
                } else {
                    break;
                }
            }
            for (meion[max, idx] : upd) {
                seg.set(idx, {f(max), idx});
            }
        } else {
            INT(x);
            UL(seg.get(--x).first);
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