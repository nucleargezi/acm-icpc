#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> a(m);
    std::cin >> a;
    sort(a, greater());
    static constexpr int c[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i{}; i < n; ++i) {
        for (int k{}; k < m; ++k) {
            c[a[k]] + i < n + 1 and chmax(dp[i + c[a[k]]], dp[i] + 1);
        }
    }
    while (n) {
        for (int x : a) {
            if (n - c[x] > -1 and dp[n - c[x]] == dp[n] - 1) {
                std::cout << x;
                n -= c[x];
                break;
            }
        }
    }
    std::cout << '\n';
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