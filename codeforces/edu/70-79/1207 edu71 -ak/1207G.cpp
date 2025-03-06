#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/acam.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    string s;
    vector<vector<int>> v(n + 1);
    for (int i{}, op, p{}; i < n; ++i, p = 0) {
        std::cin >> op;
        if (op == 2) std::cin >> p;
        char c;
        std::cin >> c;
        s += c;
        v[p].emplace_back(i + 1);
    }
    
    int m;
    std::cin >> m;
    AC ac;
    vector<int> endpos(m);
    vector<vector<int>> g(n + 1);
    for (int i{}, k; i < m; ++i) {
        string s;
        std::cin >> k >> s;
        endpos[i] = ac.add(s);
        g[k].emplace_back(i + 1);
    }
    ac.work();

    meion fail_graph = ac.get_graph();
    tree v2(fail_graph);
    const int N{fail_graph.n};
    
    vector<ll> ans(m);
    Seg<monoid_add<ll>> seg(N);
    meion dfs = [&](meion &dfs, int n, int p) -> void {
        if (n) p = ac[p][s[n - 1] - 'a'], seg.apply(v2.L[p], 1);
        for (int i : g[n]) {
            ans[i - 1] = seg.prod(v2.L[endpos[i - 1]], v2.R[endpos[i - 1]]);
        }
        for (int i : v[n]) {
            dfs(dfs, i, p);
        }
        seg.apply(v2.L[p], -1);
    };
    dfs(dfs, 0, 0);

    for (ll &x : ans) {
        std::cout << x << '\n';
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
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}