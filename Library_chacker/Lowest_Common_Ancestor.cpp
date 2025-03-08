#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

NAME MeIoN_is_UMP45() {
    int n, q;
    std::cin >> n >> q;
    graph<int> g(n);
    for (int i{1}, fa; i < n; ++i) {
        std::cin >> fa;
        g.add(fa, i);
    }
    g.build();
    tree v(g);
    for (int i{}, x, y; i < q; ++i) {
        std::cin >> x >> y;
        std::cout << v.LCA(x, y) << '\n';
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);

    MeIoN_is_UMP45();
    
    iroha 0;
}