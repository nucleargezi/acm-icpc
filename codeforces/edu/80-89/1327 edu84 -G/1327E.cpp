#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/mod/powertable.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    LL(n);
    meion ten = power_table_1(mint(10), n);
    vector<mint> ans(n, 10);
    FOR(i, n - 1) {
        ans[i] = ten[n - i - 1] * 18 + ten[n - i - 2] * (n - i - 2) * 81;
    }
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