#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/Big_int.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    vector<BigInteger> ans{0, 1, 5, 16};
    INT(n);
    FOR(i, 4, n + 1) 
        ans.emplace_back(ans[i - 1] * 3 - ans[i - 2] + 2);
    UL(ans[n]);
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