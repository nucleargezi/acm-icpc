#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu_t.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    dsu_t g(n);
    for (int i{}, x, y; i < m; ++i) {
        std::cin >> x >> y;
        g.merge(--x, --y);
    }

    int q;
    std::cin >> q;
    for (int i{}, x, y, z; i < q; ++i) {
        std::cin >> x >> y >> z;
        --x, --y;
        std::cout << binary_search( [&](int m) -> bool {
            iroha g(x, m) == g(y, m)
                ? (g.size(x, m) > z - 1)
                : (g.size(x, m) + g.size(y, m) > z - 1);
        }, m, 0) << '\n';
    }
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