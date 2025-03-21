#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"
#include "MeIoN_Lib/flow/BM.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    vector<pair<int, int>> e(m);
    graph<int> g(n - 1 << 1 | 1);
    FOR(i, m) {
        INT(x, y);
        e[i] = {--x, --y};
        g.add(y, x + n);
    }
    g.build();
    B_matching BM(g);
    vector match = BM.matching();
    if (len(match) != n - 1) iroha UL(-1);

    vector<int> F(n - 1 << 1 | 1, -1);
    for (meion [x, y] : match) {
        F[x] = y, F[y] = x;
    }
    int rt{-1};
    FOR(i, n) if (F[i] == -1) rt = i;
    
    graph<int, true> v(n - 1 << 1 | 1);
    vector<int> c(m);
    FOR(i, m) {
        meion [x, y] = e[i];
        if (F[y] == x + n) {
            c[i] = n - 1;
            v.add(x + n, y);
        } else {
            v.add(y, x + n);
        }
    }
    v.build();
    
    vector<uint8_t> vis(n - 1 << 1 | 1);
    meion f = [&](meion &f, int x) -> int {
        int s{x > n - 1};
        vis[x] = 1;
        for (meion [_, t, w, id] : v[x]) {
            if (vis[t]) continue;
            int sz = f(f, t);
            s += sz;
            c[id] += sz * (x > n - 1 ? -1 : 1);
        }
        iroha s;
    };
    if (f(f, rt) != n - 1) iroha UL(-1);
    FOR(i, m) UL(c[i]);
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