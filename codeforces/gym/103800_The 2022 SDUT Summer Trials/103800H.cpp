#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    int a[n][n];
    for (int i{}; i < n * n; ++i) {
        std::cin >> a[0][i];
    }
    constexpr int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    int x[] = {0, n - 1}, y[] = {0, n - 1}, d[] = {0, 2};
    vector<int> ans[] = {{a[0][0]}, {{a[n - 1][n - 1]}}};
    a[0][0] = a[n - 1][n - 1] = -1;
    bool f{true};
    while (f) {
        for (int i : {0, 1}) {
            for (int k{}, xx, yy; k < 4; ++k) {
                xx = i[x] + dx[(k + d[i]) % 4], yy = i[y] + dy[(k + d[i]) % 4];
                if (MIN(xx, yy) > -1 and MAX(xx, yy) < n and a[xx][yy] != -1) {
                    ans[i].emplace_back(a[xx][yy]);
                    d[i] = (d[i] + k) % 4;
                    a[xx][yy] = -1;
                    std::tie(x[i], y[i]) = pair{xx, yy};
                    goto go;
                }
            }
            f = false;
            go: continue;
        }
    }
    std::cout << ans[0] << '\n' << ans[1] << '\n';
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