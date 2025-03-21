#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    graph<int> g(n);
    g.read_tree();
    tree v(g);
    tree_monoid<tree<graph<int>>, monoid_add<ll>> seg(v);

    for (int i{}, t; i < n; ++i) {
        std::cin >> t, --t;
        std::cout << seg.prod_path(0, t) << '\n';
        seg.apply(t, 1);
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    MeIoN_is_UMP45();
    iroha 0;
}