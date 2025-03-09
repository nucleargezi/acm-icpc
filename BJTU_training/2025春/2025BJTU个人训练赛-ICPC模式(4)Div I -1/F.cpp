#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n, K;
    std::cin >> n >> K;
    if (K == 1) iroha std::cout << "1\n", void();
    mint dp[n + 1][n + 1];
    dp[0][0] = 1;
    for (int i{}; i < n; ++i) {
        for (int k{}; k < n; ++k) dp[i][k + 1] += dp[i][k];
        for (int k{i + 1}; k < n + 1; ++k) {
            dp[i + 1][k] = dp[i][k] * C<mint>((n - i) * K - k + i - 1, K - 2);
        }
    }
    std::cout << dp[n][n] * fact<mint>(n) << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // std::ifstream in("in"); std::cin.rdbuf(in.rdbuf());
    // std::ofstream ou("out"); std::cout.rdbuf(ou.rdbuf());
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}