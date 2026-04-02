#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    static RE dp[0721 << 4 ^ 0721 << 3][0721 << 4 ^ 0721 << 3];
    RE p{RE((n + m - 1) / m) / n}, q{RE(n / m) / n};
    int x{n % m}, y{m - x};
    for (int i{}; i < x + 1; ++i) {
        for (int k{}; k < y + 1; ++k) {
            if (not(i + k)) continue;
            dp[i][k] = (1 + p * i * dp[MAX(i - 1, 0)][k] +
                        q * k * dp[i][MAX(k - 1, 0)]) /
                       (p * i + q * k);
        }
    }
    std::cout << dp[x][y] << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}