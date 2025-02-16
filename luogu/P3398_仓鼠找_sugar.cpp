#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

NAME MeIoN_is_UMP45() {
    int n, q;
    std::cin >> n >> q;
    graph<int> g(n);
    g.read_tree();
    tree v(g);

    for (int i{}, a, b, c, d; i < q; ++i) {
        std::cin >> a >> b >> c >> d, --a, --b, --c, --d;
        int A{v.LCA(a, b)}, B(v.LCA(c, d));
        int ok = v.meet(a, b, B) == B or v.meet(c, d, A) == A;
        std::cout << "NY"[ok] << "\n";
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}