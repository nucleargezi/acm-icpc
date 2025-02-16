#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

NAME MeIoN_is_UMP45() {
    int n, q;
    std::cin >> n >> q;
    graph<int> g(n);
    g.read_tree();
    tree v(g);

    for (int i{}, x, y, lca; i < q; ++i) {
        std::cin >> x >> y >> lca, --x, --y, --lca;
        if (lca == x or lca == y) {
            if (x == y) {
                std::cout << n << '\n';
            } else {
                x ^= y ^ lca;
                x = v.jump(x, lca, v.dist(x, lca) - 1);
                std::cout << n - v.subtree_size(x, lca) << '\n';
            }
        } else {
            x = v.jump(x, lca, v.dist(x, lca) - 1);
            y = v.jump(y, lca, v.dist(y, lca) - 1);
            if (x == y) {
                std::cout << "0\n";
            } else {
                std::cout << n - v.subtree_size(x, lca) - v.subtree_size(y, lca)
                          << '\n';
            }
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