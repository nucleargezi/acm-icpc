#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    INT(n, m, k);
    set<pair<ll, int>> q;
    vector<ll> dis(n, inf<ll>);
    vector<int> inque(n);
    vector<int> done(n);
    FOR(k) {
        INT(x);
        q.emplace(0, --x);
        dis[x] = 0;
        done[x] = 1;
    }
    VEC(int, d, n);

    graph<ll> g(n);
    g.read_graph<true>(m);

    vector<priority_queue<ll>> L(n);
    while (not q.empty()) {
        meion [D, n] = *q.begin();
        dis[n] = D;
        q.erase(q.begin());
        done[n] = 1;
        for (meion &&[f, t, w, id] : g[n]) {
            if (done[t]) continue;
            if (inque[t]) {
                ll ps = L[t].top();
                L[t].emplace(w + D);
                L[t].pop();
                q.extract({ps, t});
                q.emplace(L[t].top(), t);
            } else {
                L[t].emplace(w + D);
                if (len(L[t]) > d[t]) {
                    q.emplace(L[t].top(), t);
                    inque[t] = 1;
                }
            }
        }
    }
    UL(dis[0] == inf<ll> ? -1 : dis[0]);
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