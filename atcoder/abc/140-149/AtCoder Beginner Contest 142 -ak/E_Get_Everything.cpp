#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (meion &[x, y] : a) {
        int sz;
        std::cin >> x >> sz;
        for (int i{}, x; i < sz; ++i) {
            std::cin >> x;
            y |= 1 << --x;
        }
    }
    vector<int> dp(1 << n, inf<int>);
    dp[0] = 0;
    for (int i{}; i < (1 << n); ++i) {
        if (dp[i] == inf<int>) continue;
        for (meion [x, y] : a) {
            chmin(dp[i | y], dp[i] + x);
        }
    }
    std::cout << (dp.back() == inf<int> ? -1 : dp.back()) << '\n';
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