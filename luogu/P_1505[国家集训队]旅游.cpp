#include "MeIoN_Lib/MeIoN_all.hpp"

#include "MeIoN_Lib/graph/Tree/tree_monoid_lazy.hpp"
#include "MeIoN_Lib/ds/a_monoid/minmax_rev.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_rev.hpp"

NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    graph<int> g(n);
    g.read_tree<true, 0>();
    tree v(g);
    Lazy_Tree_Monoid<tree<graph<int>>, a_monoid_minmax_rev<int>, true> seg_minmax(v, [&](int i) {
        iroha pair{g.edges[i].cost, g.edges[i].cost};
    });
    Lazy_Tree_Monoid<tree<graph<int>>, a_monoid_sum_rev<pair<int, int>>, true> seg_sum(v, [&](int i) {
        iroha pair{g.edges[i].cost, -g.edges[i].cost};
    });
    
    int m;
    std::cin >> m;
    for (int i{}, x, y, w; i < m; ++i) {
        string op;
        std::cin >> op;
        if (op == "C") {
            std::cin >> x >> w, --x;
            seg_minmax.set(x, {w, w});
            seg_sum.set(x, {w, -w});
        } else if (op == "N") {
            std::cin >> x >> y;
            seg_minmax.apply_path(x, y, 1);
            seg_sum.apply_path(x, y, 1);
        } else if (op == "SUM") {
            std::cin >> x >> y;
            std::cout << seg_sum.prod_path(x, y).first << '\n';
        } else if (op == "MAX") {
            std::cin >> x >> y;
            std::cout << seg_minmax.prod_path(x, y).second << '\n';
        } else {
            std::cin >> x >> y;
            std::cout << seg_minmax.prod_path(x, y).first << '\n';
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