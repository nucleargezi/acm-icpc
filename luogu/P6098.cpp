#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/xor.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<ll> w(n);
    std::cin >> w;
    graph<int> g(n);
    g.read_tree();
    tree v(g);
    tree_monoid<tree<graph<int>>, monoid_xor<ll>> seg(v, w);

    for (int i{}, x, y, op; i < m; ++i) {
        std::cin >> op >> x >> y;
        if (op == 1) {
            seg.set(--x, y);
        } else {
            std::cout << seg.prod_path(--x, --y) << '\n';
        }
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    MeIoN_is_UMP45();
    iroha 0;
}