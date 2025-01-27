#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n, m, k;
    std::cin >> n >> m >> k;
    vector<mint> fib(m + 1);
    fib[0] = fib[1] = 1;
    for (int i{2}; i < m + 1; ++i) {
        fib[i] = fib[i - 2] + fib[i - 1];
    }
    mint dp[n + 1][m];
    dp[0][0] = 1;
    --k;
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            if (not dp[i][k].val) continue;
            if (k) {
                dp[i + 1][k - 1] += dp[i][k] * fib[k - 1] * fib[m - 1 - k];
            }
            if (k < m - 1) {
                dp[i + 1][k + 1] += dp[i][k] * fib[k] * fib[m - 2 - k];
            }
            dp[i + 1][k] += dp[i][k] * fib[k] * fib[m - 1 - k];
        }
    }
    std::cout << dp[n][k] << '\n';
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