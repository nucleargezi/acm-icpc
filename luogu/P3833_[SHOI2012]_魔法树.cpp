#include "MeIoN_Lib/MeIoN_all.hpp"

#include "MeIoN_Lib/graph/Tree/tree_monoid_lazy.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_add.hpp"

NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    graph g(n);
    g.read_tree<false, 0>();
    tree v(g);
    Lazy_Tree_Monoid<tree<graph<int>>, a_monoid_sum_add<ll>> seg(v);
    
    int m;
    std::cin >> m;
    for (int i{}, x, y, w; i < m; ++i) {
        char op;
        std::cin >> op;
        if (op == 'A') {
            std::cin >> x >> y >> w;
            seg.apply_path(x, y, w);
        } else {
            std::cin >> x;
            std::cout << seg.prod_subtree(x) << '\n';
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