#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/dijkstra.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<pair<int, int>>> v(n + m << 1);
    map<pair<int, int>, int> M;
    int t{};
    for (int i{}; i < n; ++i) {
        M[{i, 0}] = t++;
    }
    for (int i{}, x, y, c; i < m; ++i) {
        std::cin >> x >> y >> c;
        --x, --y;
        for (int s : {x, y}) {
            if (M.contains({s, c})) continue;
            v[s].emplace_back(t, 1);
            v[t].emplace_back(s, 0);
            M[{s, c}] = t++;
        }
        v[M[{x, c}]].emplace_back(M[{y, c}], 0);
        v[M[{y, c}]].emplace_back(M[{x, c}], 0);
    }
    ll ans{dijkstra(v, 0).first[--n]};
    std::cout << (ans == inf<ll> ? -1 : ans) << '\n';
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