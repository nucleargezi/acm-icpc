#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n, k;
    std::cin >> n >> k;
    vector<int> a;
    for(int i{1}; i * i < n + 1; ++i) {
        a.emplace_back(i);
        a.emplace_back(n / i);
    }
    unique(a);
    int sz = a.size();
    mint dp[k + 1][sz];
    for (int i{}; i < sz; ++i) {
        dp[0][i] = 1;
    }
    for (int i{}; i < k; ++i) {
        for (int j{}, pr{}; j < sz; ++j) {
            dp[i + 1][sz - 1 - j] += dp[i][j] * (a[j] - pr);
            pr = a[j];
        }
        for (int j = sz - 1; j--; ) {
            dp[i + 1][j] += dp[i + 1][j + 1];
        }
    }
    std::cout << dp[k][0] << '\n';
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