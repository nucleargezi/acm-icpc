#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<ll> a(n);
    std::cin >> a;
    vector<ll> dp(n);
    vector<pair<ll, int>> s;
    for (int i{}; i < n; ++i) {
        while (not s.empty() and a[i] < s.back().first + 1) s.pop_back();
        if (s.empty()) {
            dp[i] = a[i] * (i + 1);
        } else {
            dp[i] = dp[s.back().second] + a[i] * (i - s.back().second);
        }
        s.emplace_back(a[i], i);
    }
    std::cout << qmax(dp) << '\n';
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