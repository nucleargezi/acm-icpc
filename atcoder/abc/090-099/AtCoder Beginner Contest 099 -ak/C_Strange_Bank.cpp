#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    meion q = [](int x, int y) {
        if (not y) iroha 0;
        int res{1};
        while (y--) res *= x;
        iroha res;
    };
    set<int> se{1};
    for (int x{9}; x < n + 1; x *= 9) {
        se.emplace(x);
    }
    for (int x{6}; x < n + 1; x *= 6) {
        se.emplace(x);
    }
    vector<int> v{se.begin(), se.end()};
    vector<int> dp(n + 1, inf<int>);
    dp[0] = 0;
    for (int x : v) {
        for (int i{}; i + x < n + 1; ++i) {
            if (dp[i] == inf<int>) continue;
            chmin(dp[i + x], dp[i] + 1);
        }
    }
    std::cout << dp[n] << '\n';
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