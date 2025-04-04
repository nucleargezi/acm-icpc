#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    S(s);
    const int n{len(s)};
    HASH L(s);
    reverse(s);
    HASH R(s);
    reverse(s);
    vector<int> dp(n + 1);
    FOR(i, n) {
        if (palindrome(L, R, 0, i + 1)) {
            dp[i + 1] = dp[i + 1 >> 1] + 1;
        }
    }
    UL(SUM(dp));
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}