#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/block_cut_tree.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    graph g(n);
    g.read_graph<false, 0>(m);
    meion v = block_cut(g);
    UL(v.n - n);
    FOR(i, n, v.n) {
        vector<int> bcc;
        for (meion &&[f, t, a, b] : v[i]) {
            bcc.emplace_back(t);
        }
        UL(len(bcc), bcc);
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