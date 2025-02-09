#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    int ms{};
    static constexpr int N{18}, x = 1 << N, y = 1 << N - 1;
    [&]() {
        int x, y, z;
        std::cin >> x >> y >> z;
        y += z, x += y;
        ms |= 1 << (N - 1 - x);
        ms |= 1 << (N - 1 - y);
        ms |= 1 << (N - 1 - z);
    }();
    mint ans = 1;
    for (int i{}; i < n; ++i) ans *= 10;
    static mint dp[41][x];
    dp[0][y] = 1;
    for (int i{}; i < n; ++i) {
        for (int k{}; k < x; ++k) {
            for (int j{1}; j < 11; ++j) {
                int s{k >> j | y};
                if (ms == (ms & s)) continue;
                dp[i + 1][s] += dp[i][k];
            }
        }
    }
    for (int i{}; i < x; ++i) {
        ans -= dp[n][i];
    }
    std::cout << ans << '\n';
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