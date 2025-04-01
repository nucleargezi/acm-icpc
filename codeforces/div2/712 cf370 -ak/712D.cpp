#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    INT(a, b, k, t);
    k <<= 1;
    mint dp[k * t + 1];
    dp[0] = 1;
    FOR(i, t) {
        FOR(j, 1, k * t + 1) {
            dp[j] += dp[j - 1];
        }
        FOR_R(j, k + 1, k * t + 1) {
            dp[j] -= dp[j - k - 1];
        }
    }
    mint ans, s;
    int p{-1};
    FOR(i, k * t + 1) {
        while (p < k * t and a + i > b + p + 1) {
            s += dp[++p];
        }
        ans += dp[i] * s;
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