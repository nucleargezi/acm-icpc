#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    string s, t;
    std::cin >> s >> t;
    while (s.length() < t.length() * 2) s += s;
    s += s;
    const int n = s.length(), m = t.length();
    HASH hs(s), ht(t);
    vector<int> dp(n + m);
    for (int i = 0, c = 0; i < n - m + 1; ++i) {
        dp[i + m] = hash_same(hs, i, ht, 0, m) ? dp[i] + 1 : 0;
    }
    int ans = qmax(dp);
    std::cout << (ans + 1 > n / m - 1 ? -1 : ans) << '\n';
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