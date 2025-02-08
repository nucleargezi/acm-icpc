#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    static constexpr int N = 12800;
    static bitset<N << 1> dp[80][80];
    int n, m;
    std::cin >> n >> m;
    int a[n][m];
    for (int i{}; i < n * m; ++i) {
        std::cin >> a[0][i];
    }
    for (int i{}, x; i < n * m; ++i) {
        std::cin >> x;
        a[0][i] = ABS(x - a[0][i]);
    }
    dp[0][0][N - a[0][0]] = 1;
    dp[0][0][N + a[0][0]] = 1;
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            if (i) dp[i][k] |= dp[i - 1][k] << a[i][k] | dp[i - 1][k] >> a[i][k];
            if (k) dp[i][k] |= dp[i][k - 1] << a[i][k] | dp[i][k - 1] >> a[i][k];
        }
    }
    int ans{N << 1};
    for (int i{}; i < (N << 1); ++i) {
        if (dp[n - 1][m - 1][i]) chmin(ans, ABS(i - N));
    }
    std::cout << ans << '\n';
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