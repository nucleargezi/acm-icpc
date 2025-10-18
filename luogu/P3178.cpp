#include "MeIoN_Lib/MeIoN_all.hpp"

#include "MeIoN_Lib/graph/Tree/tree_monoid_lazy.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_add.hpp"

NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<ll> w(n);
    std::cin >> w;
    graph g(n);
    g.read_tree();
    tree v(g);
    Lazy_Tree_Monoid<tree<graph<int>>, a_monoid_sum_add<ll>> seg(v, w);
    
    for (int i{}, op, x, y; i < m; ++i) {
        std::cin >> op;
        if (op == 1) {
            std::cin >> x >> y, --x;
            seg.apply_path(x, x, y);
        } else if (op == 2) {
            std::cin >> x >> y, --x;
            seg.apply_subtree(x, y);
        } else {
            std::cin >> x;
            std::cout << seg.prod_path(--x, 0) << '\n';
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