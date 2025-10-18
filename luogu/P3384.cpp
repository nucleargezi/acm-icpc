#include "MeIoN_Lib/MeIoN_all.hpp"

#include "MeIoN_Lib/graph/Tree/tree_monoid_lazy.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_add.hpp"
#include "MeIoN_Lib/math/mod/modint_d.hpp"

using mint = dmint;
NAME MeIoN_is_UMP45() {
    int n, m, root, mod;
    std::cin >> n >> m >> root >> mod, --root;
    mint::set_mod(mod);
    vector<mint> a(n);
    std::cin >> a;
    graph g(n);
    g.read_tree();
    tree v(g, root);
    Lazy_Tree_Monoid<tree<graph<int>>, a_monoid_sum_add<mint>> seg(v, a);
    for (int i{}, op, x, y, w; i < m; ++i) {
        std::cin >> op;
        if (op == 1) {
            std::cin >> x >> y >> w;
            seg.apply_path(--x, --y, w);
        } else if (op == 2) {
            std::cin >> x >> y;
            std::cout << seg.prod_path(--x, --y) << '\n';
        } else if (op == 3) {
            std::cin >> x >> w;
            seg.apply_subtree(--x, w);
        } else {
            std::cin >> x;
            std::cout << seg.prod_subtree(--x) << '\n';
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