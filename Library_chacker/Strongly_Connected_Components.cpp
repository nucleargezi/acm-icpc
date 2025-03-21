#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/scc.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    graph<int, true> v(n);
    v.read_graph<false, 0>(m);
    
    meion [cnt, id] = scc(v);
    meion sccs = get_scc_group(v, cnt, id);
    graph g = scc_dag(v, cnt, id);
    vector in = g.deg_array_inout().first;
    
    UL(len(sccs));
    queue<int> q;
    FOR(i, cnt) if (not in[i]) q.emplace_back(i);
    while (not q.empty()) {
        int n = q.pop();
        UL(len(sccs[n]), sccs[n]);
        for (meion &&[f, i, a, b] : g[n]) {
            if (not --in[i]) q.emplace_back(i);
        }
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