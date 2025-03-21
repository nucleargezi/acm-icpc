#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"
#include "MeIoN_Lib/flow/BM.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<vector<int>> se(n - 1);
    FOR(i, n - 1) {
        INT(sz);
        se[i].resize(sz);
        for (int &x : se[i]) IN(x), --x;
    }

    graph<int> g(n - 1 << 1 | 1);
    FOR(i, n - 1) {
        for (int x : se[i]) {
            if (x) g.add(x, i + n);
        }
    }
    g.build();
    B_matching BM(g);
    meion match = BM.matching();
    if (len(match) != n - 1) iroha UL(-1);

    vector<int> F(n - 1 << 1 | 1, -1);
    for (meion [x, y] : match) {
        F[x] = y, F[y] = x;
    }

    graph<int, true> v(n - 1 << 1 | 1);
    FOR(i, n - 1) {
        for (int x : se[i]) {
            if (F[x] == i + n) {
                v.add(i + n, x);
            } else {
                v.add(x, i + n);
            }
        }
    }
    v.build();

    queue<int> q;
    vector<int> dis(n - 1 << 1 | 1, -1), fa(n - 1 << 1 | 1, -1);
    q.emplace_back(0);
    dis[0] = 0;
    while (not q.empty()) {
        int n = q.pop();
        for (meion &&[f, t, a, b] : v[n]) {
            if (dis[t] == -1) {
                dis[t] = dis[n] + 1;
                fa[t] = n;
                q.emplace_back(t);
            }
        }
    }

    if (qmin(dis) == -1) iroha UL(-1);

    FOR(i, n - 1) {
        UL(fa[i + n] + 1, F[i + n] + 1);
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