#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> c(n);
    for (int i{}, x; i < n; ++i) {
        std::cin >> x, --x;
        ++c[x];
    }
    mint ans, dp[n];
    for (int i{}; i < n; ++i) {
        dp[i] = c[i];
        if (c[i] > 1) ans += fact<mint>(n - 2) * (c[i] - 1) * c[i];
    }
    for (int i{2}; i < n; ++i) {
        mint s;
        for (int k{}; k < n; ++k) {
            mint cp{dp[k]};
            dp[k] = s * c[k];
            s += cp;
            if (c[k] > 1) ans += fact<mint>(n - i - 1) * dp[k] * (c[k] - 1);
        }
    }
    ans /= fact<mint>(n);
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