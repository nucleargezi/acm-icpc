#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/dijkstra.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    
    graph<ll, true> v((n + m) * 2 + 0721);
    map<pair<int, int>, int> M;
    int t{};
    FOR(i, n) M[{i, 0}] = t++;
    FOR(m) {
        INT(x, y, w), --x, --y;
        for (int z : {x, y}) {
            if (not M.contains({z, w})) {
                M[{z, w}] = t++;
                v.add(z, t - 1, 1);
                v.add(t - 1, z, 0);
            }
        }
        v.add(M[{x, w}], M[{y, w}], 0);
        v.add(M[{y, w}], M[{x, w}], 0);
    }
    v.build();

    int ans = dijkstra(v, 0).first[--n];
    UL(ans == inf<ll> ? -1 : ans);
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