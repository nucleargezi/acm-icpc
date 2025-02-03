#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    mint dp[072][072][0721 << 3];
    dp[1][0][0] = dp[1][1][2] = 1;
    for (int i = 1; i < n + 1; ++i) {
        for (int k = 0; k < i + 1; ++k) {
            for (int j = 0; j < n * n + 1; ++j) {
                dp[i + 1][k][j + k + k] += dp[i][k][j];
                if (k) {
                    dp[i + 1][k][j + k + k] += dp[i][k][j] * 2 * k;
                    dp[i + 1][k - 1][j + 2 * (k - 1)] += dp[i][k][j] * k * k;
                }
                dp[i + 1][k + 1][j + 2 * (k + 1)] += dp[i][k][j];
            }
        }
    }
    std::cout << dp[n][0][m] << '\n';
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