#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"
void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    S(s);
    HASH h(s);
    UL(binary_search([&](int m) -> bool {
        FOR(i, n - m + 1) {
            FOR(k, m + i, n - m + 1) {
                if (hash_same(h, i, h, k, m)) iroha true;
            }
        }
        iroha false;
    }, 0, n + 1));
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