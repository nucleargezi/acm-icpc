#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(int, a, n);
    multiset<int> se{2, 0, 2, 5, 0, 3, 0, 1};
    FOR(i, n) {
        if (se.contains(a[i])) se.extract(a[i]);
        if (se.empty()) iroha UL(i + 1);
    }
    UL(0);
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