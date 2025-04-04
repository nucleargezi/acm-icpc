#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    int a[n][n], b[n][n];
    int px{-1}, py{-1};
    FOR(i, n) FOR(k, n) {
        INT(x);
        int t{}, f{};
        while (x and x & 1 ^ 1) x >>= 1, ++t;
        while (x and x % 5 == 0) x /= 5, ++f;
        if (not x) px = i, py = k, f = t = 1;
        a[i][k] = t, b[i][k] = f;
    }
    int ans{inf<int>};
    int dp[n][n];
    char fa[n][n];
    std::fill(&dp[0][0], &dp[0][n * n], inf<int>);
    dp[0][0] = a[0][0];
    FOR(i, n) FOR(k, n) {
        if (i + 1 < n and chmin(dp[i + 1][k], dp[i][k] + a[i + 1][k])) {
            fa[i + 1][k] = 'D';
        }
        if (k + 1 < n and chmin(dp[i][k + 1], dp[i][k] + a[i][k + 1])) {
            fa[i][k + 1] = 'R';
        }
    }
    chmin(ans, dp[0][n * n - 1]);
    int x{n - 1}, y{n - 1};
    string path;
    while (x or y) {
        path += fa[x][y];
        if (fa[x][y] == 'D') --x;
        else --y;
    }
    reverse(path);
    std::fill(&dp[0][0], &dp[0][n * n], inf<int>);
    dp[0][0] = b[0][0];
    FOR(i, n) FOR(k, n) {
        if (i + 1 < n and chmin(dp[i + 1][k], dp[i][k] + b[i + 1][k])) {
            fa[i + 1][k] = 'D';
        }
        if (k + 1 < n and chmin(dp[i][k + 1], dp[i][k] + b[i][k + 1])) {
            fa[i][k + 1] = 'R';
        }
    }
    if (chmin(ans, dp[0][n * n - 1])) {
        path = "";
        x = n - 1, y = n - 1;
        while (x or y) {
            path += fa[x][y];
            if (fa[x][y] == 'D') --x;
            else --y;
        }
        reverse(path);
    }
    if (px != -1 and chmin(ans, 1)) {
        path = string(px, 'D') + string(py, 'R') + string(n - px - 1, 'D') + string(n - py - 1, 'R');
    }
    UL(ans);
    UL(path);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}