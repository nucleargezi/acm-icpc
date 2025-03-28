#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<int> c(n + 1);
    FOR(i, 1, n) {
        INT(fa);
        ++c[fa];
    }
    ++c[0];
    sort(c, greater());
    UL(binary_search([&](ll m) -> bool {
        ll s{};
        FOR(i, n) {
            if (not c[i]) continue;
            s += MAX(1ll, c[i] - m + i + 1);
        }
        iroha s <= m;
    }, n, 0));
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