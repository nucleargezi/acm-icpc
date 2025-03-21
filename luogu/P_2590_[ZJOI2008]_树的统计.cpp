#include "MeIoN_Lib/MeIoN_all.hpp"

#include "MeIoN_Lib/graph/Tree/tree_monoid_lazy.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_cov.hpp"
#include "MeIoN_Lib/ds/a_monoid/max_cov.hpp"

NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    graph g(n);
    g.read_tree();
    tree v(g);
    vector<int> w(n);
    std::cin >> w;
    Lazy_Tree_Monoid<tree<graph<int>>, a_monoid_sum_cov<int>> seg_sum(v, w);
    Lazy_Tree_Monoid<tree<graph<int>>, a_monoid_max_cov<int>> seg_max(v, w);
    
    int m;
    std::cin >> m;
    for (int i{}, x, y; i < m; ++i) {
        string op;
        std::cin >> op;
        if (op == "QMAX") {
            std::cin >> x >> y;
            std::cout << seg_max.prod_path(--x, --y) << '\n';
        } else if (op == "QSUM") {
            std::cin >> x >> y;
            std::cout << seg_sum.prod_path(--x, --y) << '\n';
        } else {
            std::cin >> x >> y, --x;
            seg_sum.set(x, y);
            seg_max.set(x, y);
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