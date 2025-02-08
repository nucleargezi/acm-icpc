#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/floyd.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, l;
    std::cin >> n >> m >> l;
    vector<tuple<int, int, ll>> e(m);
    for (meion &[x, y, w] : e) {
        std::cin >> x >> y >> w;
        --x, --y;
    }
    constexpr ll INF = inf<ll> >> 1;
    meion dis = floyd<300, ll>(e, n);
    e.clear();
    for (int i{}; i < n; ++i) {
        for (int k{}; k < n; ++k) {
            if (dis[i][k] > l) continue;
            e.emplace_back(i, k, 1);
        }
    }
    meion res = floyd<300, ll>(e, n);
    int q;
    std::cin >> q;
    for (int i{}, s, t; i < q; ++i) {
        std::cin >> s >> t;
        --s, --t;
        std::cout << (res[s][t] == INF ? -1 : res[s][t] - 1) << '\n';
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