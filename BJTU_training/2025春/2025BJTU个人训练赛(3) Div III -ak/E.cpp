#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/bellman_ford.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, p;
    std::cin >> n >> m >> p;
    graph<ll, true> g(n);
    for (int i{}, x, y, w; i < m; ++i) {
        std::cin >> x >> y >> w;
        g.add(--x, --y, p - w);
    }
    g.build();
    meion dis = bellman_ford<ll, false>(g, 0).first[--n];
    std::cout << ((dis == -inf<ll>) ? -1 : MAX(0ll, -dis)) << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // std::ifstream in("in"); std::cin.rdbuf(in.rdbuf());
    // std::ofstream ou("out"); std::cout.rdbuf(ou.rdbuf());
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}