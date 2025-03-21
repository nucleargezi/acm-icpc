#include "MeIoN_Lib/MeIoN_all.hpp"

#include "MeIoN_Lib/graph/Tree/tree_monoid_lazy.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_cov.hpp"

NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    graph g(n);
    for (int i{1}, x; i < n; ++i) {
        std::cin >> x;
        g.add(x, i);
    }
    g.build();
    tree v(g);
    Lazy_Tree_Monoid<tree<graph<int>>, a_monoid_sum_cov<int>> seg(v);
    
    int m;
    std::cin >> m;
    for (int i{}, x; i < m; ++i) {
        string op;
        std::cin >> op;
        if (op[0] == 'i') {
            std::cin >> x;
            int ans = seg.prod_path(x, 0);
            seg.apply_path(x, 0, 1);
            ans -= seg.prod_path(x, 0);
            std::cout << ABS(ans) << '\n';
        } else {
            std::cin >> x;
            int ans = seg.prod_subtree(x);
            seg.apply_subtree(x, 0);
            ans -= seg.prod_subtree(x);
            std::cout << ABS(ans) << '\n';
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