#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid_lazy.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    graph<int> g(n);
    g.read_tree();
    tree v(g);
    Lazy_Tree_Monoid<tree<graph<int>>, a_monoid_sum_add<int>, true> seg(v);

    vector<pair<int, int>> go;
    for (int i{}, x, y; i < m; ++i) {
        char op;
        std::cin >> op;
        if (op == 'Q') {
            std::cin >> x >> y;
            No(seg.prod_path(--x, --y));
        } else if (op == 'C') {
            std::cin >> x >> y;
            go.emplace_back(--x, --y);
            seg.apply_path(x, y, 1);
        } else if (op == 'U') {
            std::cin >> x, --x;
            seg.apply_path(go[x].first, go[x].second, -1);
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