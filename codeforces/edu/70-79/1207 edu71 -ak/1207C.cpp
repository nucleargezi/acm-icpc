#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, a, b;
    string str;
    std::cin >> n >> a >> b >> str;
    vector s = s_to_vec(str, '0');
    vector dp(2, vector<ll>(n, inf<ll> >> 1));
    dp[0][0] = a + b + b;
    dp[1][0] = s[0] ? 0 : a + a + b + b + b;
    for (int i{1}; i < n; ++i) {
        if (s[i]) {
            dp[0][i] = inf<ll> >> 1;
            dp[1][i] = dp[1][i - 1] + a + b + b;
        } else {
            dp[0][i] = MIN(dp[0][i - 1], dp[1][i - 1] + a) + a + b;
            dp[1][i] = MIN(dp[0][i - 1] + a, dp[1][i - 1]) + a + b + b;
        }
    }
    std::cout << dp[s[n - 1]][n - 1] << '\n';
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