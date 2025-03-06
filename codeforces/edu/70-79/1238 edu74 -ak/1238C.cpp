#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int h, n;
    std::cin >> h >> n;
    vector<int> a(n), dp(n + 1);
    std::cin >> a;
    a.emplace_back(0);
    for (int i{n - 1}; i--; ) {
        dp[i] = h;
        if (i + 1 < n and a[i + 1] == a[i + 2] + 1) chmin(dp[i], dp[i + 2]);
        chmin(dp[i], dp[i + 1] + 1);
    }
    std::cout << dp[0] << '\n';
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