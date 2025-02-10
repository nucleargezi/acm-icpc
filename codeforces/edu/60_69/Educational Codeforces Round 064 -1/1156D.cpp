#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    dsu g[] = {dsu(n), dsu(n)};
    for (int i{1}, x, y, z; i < n; ++i) {
        std::cin >> x >> y >> z;
        --x, --y;
        g[z].merge(x, y);
    }
    ll ans{};
    for (int i{}; i < n; ++i) {
        if (g[0][i] == i) {
            ans += (ll)g[0].size(i) * (g[0].size(i) - 1);
        }
        if (g[1][i] == i) {
            ans += (ll)g[1].size(i) * (g[1].size(i) - 1);
        }
        ans += ll(g[0].size(i) - 1) * (g[1].size(i) - 1);
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