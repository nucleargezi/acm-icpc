#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector a(n, vector<int>(m));
    std::cin >> a;
    map<int, int> M;
    for (int i{}, t{}; i < n; ++i) {
        for (int k{}; k < m; ++k, ++t) {
            if (not M.contains(a[i][k])) {
                M[a[i][k]] = 1;
            }
            if (i and a[i][k] == a[i - 1][k]) M[a[i][k]] = 2;
            if (k and a[i][k] == a[i][k - 1]) M[a[i][k]] = 2;
        }
    }
    int s{}, ans{inf<int>};
    for (meion [x, y] : M) s += y;
    for (meion [x ,y] : M) chmin(ans, s - y);
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