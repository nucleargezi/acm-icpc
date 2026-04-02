#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    vector<int> dp(5, -inf<int>);
    dp[0] = 0;
    FOR(n) {
        S(s);
        vector cp(dp);
        for (char c : s) {
            int x {c == 'n'   ? 0
                   : c == 'a' ? 1
                   : c == 'r' ? 2
                   : c == 'e' ? 3
                   : c == 'k' ? 4
                              : -1};
            if (x == -1) continue;
            vector<int> t(5, -inf<int>);
            FOR(i, 5) {
                if (i == x) chmax(t[(i + 1) % 5], dp[i] + 5 * ((i + 1) / 5));
                else chmax(t[i], dp[i] - 1);
            }
            dp.swap(t);
        }
        FOR(i, 5) chmax(dp[i], cp[i]);
    }
    int ans{};
    FOR(i, 5) chmax(ans, dp[i] - i);
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