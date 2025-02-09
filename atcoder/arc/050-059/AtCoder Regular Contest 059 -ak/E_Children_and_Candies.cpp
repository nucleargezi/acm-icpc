#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/ntt_fft.hpp"

void before() {}

// #define tests
using poly = vector<modint<mod17>>;
NAME MeIoN_is_UMP45() {
    int n, c;
    std::cin >> n >> c;
    vector<int> a(n), b(n);
    std::cin >> a >> b;
    poly dp{1};
    for (int i{}; i < n; ++i) {
        int x{a[i]}, y{b[i] + 1};
        poly f(c + 1), pow(y, 1);
        for (int i{}; i < c + 1; ++i) {
            for (int k{x}; k < y; ++k) {
                f[i] += pow[k];
            }
            for (int i{}; i < y; ++i) {
                pow[i] *= i;
            }
        }
        dp = convolution(f, dp);
        dp.resize(c + 1);
    }
    std::cout << dp[c] << '\n';
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