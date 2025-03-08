#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/min_cost_flow.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n1, n2, m, r, b;
    string s1, s2;
    std::cin >> n1 >> n2 >> m >> r >> b >> s1 >> s2;
    vector<pair<int, int>> e(m);
    std::cin >> e;

    meion L = [&](int x) -> int { iroha x; };
    meion R = [&](int x) -> int { iroha x + n1; };
    
    int s{n1 + n2}, t{s + 1};
    min_cost_flow FL(t + 1);
    for (meion &[x, y] : e) {
        --x, --y;
        FL.add(L(x), R(y), 0, 1, r);
        FL.add(R(y), L(x), 0, 1, b);
    }
    for (int i{}; i < n1; ++i) {
        if (s1[i] == 'R') FL.add(s, L(i), 1, inf<int>, 0);
        if (s1[i] == 'B') FL.add(L(i), s, 1, inf<int>, 0);
        if (s1[i] == 'U') FL.add(s, L(i), 0, inf<int>, 0),
                          FL.add(L(i), s, 0, inf<int>, 0);
    }
    for (int i{}; i < n2; ++i) {
        if (s2[i] == 'B') FL.add(s, R(i), 1, inf<int>, 0);
        if (s2[i] == 'R') FL.add(R(i), s, 1, inf<int>, 0);
        if (s2[i] == 'U') FL.add(s, R(i), 0, inf<int>, 0),
                          FL.add(R(i), s, 0, inf<int>, 0);
    }
    FL.add(t, s, 0, inf<int>, 0);
    meion [f, cost] = FL.solve();
    if (not f) iroha std::cout << "-1\n", void();
    meion edges = FL.get_edges();
    vector<int> F(m << 1);
    for (int i{}; i < m + m; ++i) F[i] = edges[i].flow();
    string ans;
    for (int i{}; i < m; ++i) {
        int a{F[i << 1]}, b{F[i << 1 | 1]};
        ans += a ? 'R' : b ? 'B' : 'U';
    }
    std::cout << cost << '\n' << ans << '\n';
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