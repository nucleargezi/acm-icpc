#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    meion [v, n] = []() {
        string s;
        std::cin >> s;
        iroha pair{s_to_vec(s, '0'), s.size()};
    }();
    mint dp[n + 1][13];
    dp[0][0] = 1;
    for (int i{}, x; i < n; ++i) {
        x = v[i];
        if (x == -1) {
            for (int k{}; k < 13; ++k) {
                for (int x{}; x < 10; ++x) {
                    dp[i + 1][(k * 10 + x) % 13] += dp[i][k];
                }
            }
        } else {
            for (int k{}; k < 13; ++k) {
                dp[i + 1][(k * 10 + x) % 13] = dp[i][k];
            }
        }
    }
    std::cout << dp[n][5] << '\n';
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