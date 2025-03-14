#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    ll l, r;
    std::cin >> l >> r;
    mint dp[61][2][2][2];
    dp[60][0][0][0] = 1;
    for (int i{60}; i--; ) {
        int lbit{l >> i & 1}, rbit{r >> i & 1};
        for (int k : {0, 1}) {
            for (int j : {0, 1}) {
                for (int o : {0, 1}) {
                    mint cp{dp[i + 1][k][j][o]};
                    for (int x : {0, 1}) {
                        for (int y : {0, 1}) {
                            if ((x and not y) or (not o and x != y) or
                                (not k and not x and lbit) or
                                (not j and y and not rbit)) {
                                continue;
                            }
                            dp[i][k | (x and not lbit)][j | (not y and rbit)]
                              [o | (x and y)] += cp;
                        }
                    }
                }
            }
        }
    }
    mint ans{};
    for (int i{}; i < 8; ++i) ans += dp[0][0][0][i];
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // std::ifstream in("in"); std::cin.rdbuf(in.rdbuf());
    // std::ofstream ou("out"); std::cout.rdbuf(ou.rdbuf());
#ifdef tests
std::cin >> T;
#endif
while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}