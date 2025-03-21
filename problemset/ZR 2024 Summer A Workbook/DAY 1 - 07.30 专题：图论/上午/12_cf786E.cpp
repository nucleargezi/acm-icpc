#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"
#include "MeIoN_Lib/flow/BM_dense.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    graph<int> g(n);
    g.read_tree();
    tree v(g);
    
    vector<bitset<20'000>> adj(m);
    FOR(i, m) {
        INT(x, y);
        --x, --y;
        if (v.deep[x] > v.deep[y]) std::swap(x, y);
        while (v.deep[x] < v.deep[y]) {
            adj[i][y] = 1;
            y = v.fa[y];
        }
        while (x != y) {
            adj[i][x] = adj[i][y] = 1;
            x = v.fa[x];
            y = v.fa[y];
        }
    }
    
    B_matching_dense BM(adj, m, n);
    meion [X, Y] = BM.vertex_cover();
    for (int &x : X) ++x;
    for (int &x : Y) x = v.v_to_e(x) + 1;
    
    UL(len(X) + len(Y));
    UL(len(X), X);
    UL(len(Y), Y);
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