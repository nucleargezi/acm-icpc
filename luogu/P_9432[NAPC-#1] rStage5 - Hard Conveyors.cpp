#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid.hpp"
#include "MeIoN_Lib/ds/monoid/min.hpp"
#include "MeIoN_Lib/graph/Apck/dijkstra.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, q, k;
    std::cin >> n >> q >> k;
    graph<ll> g(n);
    g.read_tree<true>();
    tree v(g);
    vector<int> s(k);
    for (int i{}, x; i < k; ++i) {
        std::cin >> x;
        s[i] = --x;
    }

    meion dis = dijkstra<ll>(g, s).first;
    for (int i{}; i < n; ++i) {
        dis[i] <<= 1;
    }
    tree_monoid<tree<graph<ll>>, monoid_min<ll>, false> seg(v, dis);

    for (ll i{}, s, t, lca, deep; i < q; ++i) {
        std::cin >> s >> t;
        lca = v.LCA(--s, --t);
        std::cout << v.dist_weighted(s, t) + seg.prod_path(s, t) << '\n';
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