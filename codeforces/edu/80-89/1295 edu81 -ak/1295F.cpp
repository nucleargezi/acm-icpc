#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<pair<int, int>> range(n);
    mint bas{1};
    vector<int> f;
    for (meion &[l, r] : range) {
        std::cin >> l >> r;
        bas *= r - l + 1;
        f.emplace_back(l);
        f.emplace_back(r + 1);
    }
    reverse(range);
    unique(f);
    const int m{len(f)};
    mint dp[n + 1][m];
    for (int i{}; i < m; ++i) {
        dp[n][i] = 1;
    }
    for (int i{n}; i--; ) {
        for (int k{m - 1}; k--; ) {
            dp[i][k] = dp[i][k + 1];
            int d{f[k + 1] - f[k]};
            mint x{1};
            for (int j{i}; j < n and range[j].first < f[k] + 1 and
                            f[k + 1] < range[j].second + 2;
                 ++j) {
                x *= mint(d + j - i) / (j - i + 1);
                dp[i][k] += x * dp[j + 1][k + 1];
            }
        }
    }
    std::cout << dp[0][0] / bas << '\n';
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