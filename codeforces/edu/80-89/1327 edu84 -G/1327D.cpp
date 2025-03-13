#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/path_cycle.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(ll, p, n);
    VEC(ll, c, n);
    graph<bool, true> g(n);
    FOR(i, n) {
        g.add(i, --p[i]);
    }
    g.build();
    meion [paths, cycs] = path_cycle(g);
    
    int ans{inf<int>};
    for (meion &cyc : cycs) {
        int l{len(cyc)};
        vector<int> e;
        for (int i{1}; i * i < l + 1; ++i) {
            if (l % i) continue;
            e.emplace_back(i);
            e.emplace_back(l / i);
        }
        for (unique(e); int e : e) {
            FOR(i, e) {
                bool f{true};
                FOR(k, i, l, e) {
                    f &= c[cyc[k]] == c[cyc[i]];
                }
                if (f) {
                    chmin(ans, e);
                    break;
                }
            }
        }
    }
    UL(ans);
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