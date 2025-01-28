#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/sieve.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    sieve(0721);
    vector<int> c(25);
    for (int i{1}; i < n + 1; ++i) {
        int p{i};
        for (int i{}; int x : primes) {
            while (p % x == 0) {
                p /= x;
                ++c[i];
            }
            ++i;
        }
    }
    static ll dp[26][76];
    dp[0][1] = 1;
    for (int i{}; i < 25; ++i) {
        for (int k{1}; k < 76; ++k) {
            for (int j{0}; j < c[i] + 1; ++j) {
                if (k * (j + 1) < 76) {
                    dp[i + 1][k * (j + 1)] += dp[i][k];
                }
            }
        }
    }
    std::cout << dp[25][75] << '\n';
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