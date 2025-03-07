#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    array<int, 3> n;
    std::cin >> n;
    const int s{qsum(n, 0)};
    vector<int> a(s);
    for (int i{}; i < 3; ++i) {
        for (int k{}, x; k < n[i]; ++k) {
            std::cin >> x;
            a[--x] = i;
        }
    }
    array<int, 3> dp{}, newdp{};
    for (int x : a) {
        if (x == 0) {
            newdp[0] = dp[0];
            newdp[1] = MIN(dp[0], dp[1]) + 1;
            newdp[2] = MIN(dp[0], dp[1], dp[2]) + 1;
        } else if (x == 1) {
            newdp[0] = dp[0] + 1;
            newdp[1] = MIN(dp[0], dp[1]);
            newdp[2] = MIN(dp[0], dp[1], dp[2]) + 1;
        } else {
            newdp[0] = dp[0] + 1;
            newdp[1] = MIN(dp[0], dp[1]) + 1;
            newdp[2] = MIN(dp[0], dp[1], dp[2]);
        }
        dp.swap(newdp);
    }
    std::cout << qmin(dp) << '\n';
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