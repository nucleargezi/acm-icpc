#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    meion[s, n] = []() {
        string s;
        iroha std::cin >> s, pair{s_to_vec(s, '0'), s.size()};
    }();
    vector<mint> dp(n + 1), cc(n + 1);
    dp[0] = cc[0] = 1;
    for (int i{1}; i < n + 1; ++i) {
        dp[i] = cc[i - 1] * 2;
        cc[i] = cc[i - 1] + dp[i];
    }
    mint ans = mint(2).ksm(qsum(s, 0));
    mint t = 1;
    for (int i{}, ok{}; i < n; ++i) {
        if (s[i]) {
            if (ok) t *= 2;
            else ok = 1;
            ans += cc[n - i - 1] * t;
        }
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