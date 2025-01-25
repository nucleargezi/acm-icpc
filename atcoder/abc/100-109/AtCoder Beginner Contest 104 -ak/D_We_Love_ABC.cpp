#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    string s;
    std::cin >> s;
    const int n = s.length();
    mint dp[n + 1][4];
    dp[0][0] = 1;
    for (int i{}; i < n; ++i) {
        if (s[i] == '?') {
            dp[i + 1][0] = dp[i][0] * 3;
            dp[i + 1][1] = dp[i][1] * 3 + dp[i][0];
            dp[i + 1][2] = dp[i][2] * 3 + dp[i][1];
            dp[i + 1][3] = dp[i][3] * 3 + dp[i][2];
        } else {
            dp[i + 1][0] = dp[i][0], dp[i + 1][1] = dp[i][1];
            dp[i + 1][2] = dp[i][2], dp[i + 1][3] = dp[i][3];
            if (s[i] == 'A') dp[i + 1][1] = dp[i][1] + dp[i][0];
            if (s[i] == 'B') dp[i + 1][2] = dp[i][2] + dp[i][1];
            if (s[i] == 'C') dp[i + 1][3] = dp[i][3] + dp[i][2];
        }
    }
    std::cout << dp[n][3] << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}