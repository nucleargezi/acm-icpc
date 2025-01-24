#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) {
        std::cin >> x, --x;
    }
    dsu g(n);
    for (int i{}, x, y; i < m; ++i) {
        std::cin >> x >> y, --x, --y;
        g.merge(x, y);
    }
    int ans{};
    for (int i{}; i < n; ++i) {
        ans += g[i] == g[a[i]];
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