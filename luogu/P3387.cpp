#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/scc.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    VEC(int, a, n);
    graph<int, true> v(n);
    v.read_graph(m);
    
    meion [cnt, id] = scc(v);
    graph g = scc_dag(v, cnt, id);
    
    vector<ll> w(cnt);
    FOR(i, n) w[id[i]] += a[i];
    vector in = g.deg_array_inout().first;
    
    vector<ll> dp(cnt);
    queue<int> q;
    FOR(i, cnt) if (not in[i]) q.emplace_back(i);
    while (not q.empty()) {
        int n = q.pop();
        dp[n] += w[n];
        for (meion &&[f, i, a, b] : g[n]) {
            chmax(dp[i], dp[n]);
            if (not --in[i]) q.emplace_back(i);
        }
    }
    UL(qmax(dp));
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