#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    bool v[n + 1][m + 1];
    int a[n + 1][m + 1];
    memset(a, 0, sizeof a);
    memset(v, 0, sizeof v);
    for (int i{1}; i < n + 1; ++i) {
        for (int k{1}; k < m + 1; ++k) {
            char c;
            std::cin >> c;
            v[i][k] = a[i][k] = c == '.';
        }
    }
    for (int i{1}; i < n + 1; ++i) {
        for (int k{1}; k < m + 1; ++k) {
            a[i][k] += a[i][k - 1];
        }
        for (int k{1}; k < m + 1; ++k) {
            a[i][k] += a[i - 1][k];
        }
    }
    int ans{inf<int>};
    for (int i{1}; i < n + 1; ++i) {
        for (int k{1}; k < m + 1; ++k) {
            chmin(ans, a[n][k] - a[n][k - 1] + a[i][m] - a[i - 1][m] - v[i][k]);
        }
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