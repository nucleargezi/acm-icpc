#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    graph<int> g(n);
    g.read_tree();
    tree v(g);
    tree_monoid<tree<graph<int>>, monoid_add<int>> seg(v);
    seg.apply(0, 1);

    for (int i{}, x; i < m; ++i) {
        char op;
        std::cin >> op >> x, --x;
        if (op == 'C') {
            seg.apply(x, 1);
        } else {
            int d = v.deep[x];
            d = binary_search([&](int up) -> bool {
                int p = v.jump(x, 0, up);
                iroha seg.prod_path(x, p);
            }, d, -1);
            std::cout << v.jump(x, 0, d) + 1 << '\n';
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