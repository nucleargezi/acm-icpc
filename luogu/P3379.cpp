#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

NAME MeIoN_is_UMP45() {
    int n, m, root;
    std::cin >> n >> m >> root;
    graph<int> g(n);
    g.read_tree();
    tree v(g, --root);
    for (int i{}, x, y; i < m; ++i) {
        std::cin >> x >> y;
        std::cout << v.LCA(--x, --y) + 1 << '\n';
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);

    MeIoN_is_UMP45();
    
    iroha 0;
}