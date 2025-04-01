#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/tree_diameter.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, k);
    graph g(n);
    FOR(i, k) g.add(0, i + 1);
    FOR(i, k, n - 1) g.add(i - k + 1, i + 1);
    g.build();

    UL(tree_diameter(g).first);
    for (meion &&[x, y, a, b] : g.edges) {
        UL(++x, ++y);
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}