#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    bool v[n + 2][m + 2];
    for (int i{}; i < n; ++i) for (int k{}; k < m; ++k) {
        char c;
        std::cin >> c;
        v[i + 1][k + 1] = c == '#';
    }
    int l[n + 2][m + 2], r[n + 2][m + 2], u[n + 2][m + 2], d[n + 2][m + 2];
    memset(l, 0, sizeof l);
    memset(u, 0, sizeof u);
    for (int i{}, E = (n + 2) * (m + 2); i < E; ++i) {
        r[0][i] = m + 1;
    }
    for (int i{}, E = (n + 2) * (m + 2); i < E; ++i) {
        d[0][i] = n + 1;
    }
    for (int i{1}; i < n + 1; ++i) {
        for (int k{1}; k < m + 1; ++k) {
            l[i][k] = v[i][k] ? k : l[i][k - 1];
        }
        for (int k{m}; k; k--) {
            r[i][k] = v[i][k] ? k : r[i][k + 1];
        }
    }
    for (int i{1}; i < m + 1; ++i) {
        for (int k{1}; k < n + 1; ++k) {
            u[k][i] = v[k][i] ? k : u[k - 1][i];
        }
        for (int k{n}; k; k--) {
            d[k][i] = v[k][i] ? k : d[k + 1][i];
        }
    }
    int ans{};
    for (int i{1}; i < n + 1; ++i) {
        for (int k{1}; k < m + 1; ++k) {
            chmax(ans, r[i][k] - l[i][k] + d[i][k] - u[i][k] - 3);
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