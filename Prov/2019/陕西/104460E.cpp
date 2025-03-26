#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(n, k);
    SV(s, '0');
    UL(binary_search([&](ll m) -> bool {
        int c{};
        FOR(i, n) if (s[i] == 1) {
            i += m - 1;
            ++c;
        }
        iroha c < k + 1;
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