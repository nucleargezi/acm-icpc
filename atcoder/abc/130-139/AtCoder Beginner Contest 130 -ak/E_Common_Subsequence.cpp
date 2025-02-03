#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/string/hash.hpp"
#include "MeIoN_Lib/ds/hashmap.hpp"

void before() {}

// #define tests
using mint = modint<mod17>;
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> a(n), b(m);
    std::cin >> a >> b;
    mint dp[n][m];
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            dp[i][k] += i ? dp[i - 1][k] : 1;
            dp[i][k] += k ? dp[i][k - 1] : 1;
            dp[i][k] -= (i and k) ? dp[i - 1][k - 1] : 1;
            if (a[i] == b[k]) dp[i][k] += (i and k) ? dp[i - 1][k - 1] : 1;
        }
    }
    std::cout << dp[--n][--m] << '\n';
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