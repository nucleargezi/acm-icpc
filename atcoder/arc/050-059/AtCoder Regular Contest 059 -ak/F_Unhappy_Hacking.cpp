#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n;
    string s;
    std::cin >> n >> s;
    const int m = (int)s.length();
    mint dp[n + 1][n + 2];
    dp[0][0] = 1;
    for (int i{1}; i < n + 1; ++i) {
        for (int k{}; k < n + 1; ++k) {
            dp[i][k] = dp[i - 1][MAX(0, k - 1)] + dp[i - 1][k + 1] * 2;
        }
    }
    std::cout << dp[n][m] << '\n';
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