#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/BM.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(L, R, m);
    graph<int> v(L + R);
    FOR(m) {
        INT(x, y);
        v.add(--x, --y + L);
    }
    v.build();

    B_matching BM(v);
    meion match = BM.matching();
    UL(len(match));
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