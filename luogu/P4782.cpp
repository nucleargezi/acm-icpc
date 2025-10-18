#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/2_sat.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    TwoSat g(n);
    for (int i{}, x, y, a, b; i < m; ++i) {
        std::cin >> x >> a >> y >> b;
        --x, --y;
        g.either(x, y, a, b);
    }
    if (g.solve()) {
        POSSIBLE();
        meion res = g.answer();
        for (int i{}; i < n; ++i) {
            std::cout << (int)res[i] << " \n"[i + 1 == n];
        }
    } else {
        IMPOSSIBLE();
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