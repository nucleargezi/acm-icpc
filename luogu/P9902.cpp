#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow_HLPP.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m, k);
    HLPP FL(n, m, 0, n - 1);
    FOR(i, m) {
        INT(x, y, w);
        FL.add(--x, --y, w);
    }
    UL(FL.flow());
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