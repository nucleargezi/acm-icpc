#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/min_cost_flow.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    min_cost_flow FL(n);
    for (int i{}, x; i < n; ++i) {
        std::cin >> x;
        FL.add_source(i, x);
    }
    for (int i{}, x, y, l, r, c; i < m; ++i) {
        std::cin >> x >> y >> l >> r >> c;
        FL.add(x, y, l, r, c);
    }
    meion [f, cost] = FL.solve();
    if (not f) iroha std::cout << "infeasible\n", void();
    std::cout << cost << '\n';
    for (meion x : FL.get_potential()) {
        std::cout << x << '\n';
    }
    for (meion e : FL.get_edges()) {
        std::cout << e.flow() << '\n';
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