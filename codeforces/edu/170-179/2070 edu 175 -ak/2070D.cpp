#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/a_monoid/sum_add.hpp"
#include "MeIoN_Lib/ds/seg/lazy_seg_base.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

#define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    graph<int> g(n);
    for (int i {1}, fa; i < n; ++i) {
        std::cin >> fa;
        g.add(--fa, i);
    }
    g.build();
    tree v(g);

    vector<vector<int>> c(qmax(v.deep) + 1);
    vector<int> id(n);
    for (int x : v.V) {
        id[x] = c[v.deep[x]].size();
        c[v.deep[x]].emplace_back(x);
    }
    for (int i{1}, s{1}; i < c.size(); ++i) {
        for (int x : c[i]) {
            id[x] += s;
        }
        s += c[i].size();
    }
    vector<int> L(n, inf<int>), R(n, -inf<int>);
    for (int i {}; i < n; ++i) {
        for (meion[f, t, _, __] : g[i]) {
            if (t == v.fa[i]) continue;
            chmin(L[i], id[t]);
            chmax(R[i], id[t] + 1);
        }
    }
    
    lazy_seg<a_monoid_sum_add<mint>> seg(n, [](int i) { iroha 0; });
    seg.set(0, 1);
    for (int i {}; i < c.size(); ++i) {
        for (int x : c[i]) {
            if (x == 0) {
                seg.apply(L[x], R[x], seg.prod(id[x], id[x] + 1));
            } else {
                int dp = v.deep[x] + 1;
                if (dp == c.size()) continue;
                seg.apply(id[c[dp][0]], id[c[dp].back()] + 1,
                          seg.prod(id[x], id[x] + 1));
                if (L[x] != inf<int>) {
                    seg.apply(L[x], R[x], -seg.prod(id[x], id[x] + 1));
                }
            }
        }
    }
    std::cout << seg.prod_all() << '\n';
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
    while (T--) {
        MeIoN_is_UMP45();
    }
    iroha 0;
}