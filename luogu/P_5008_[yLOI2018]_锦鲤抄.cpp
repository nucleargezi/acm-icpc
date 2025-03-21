#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/scc.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m, k;
    std::cin >> n >> m >> k;
    vector<int> w(n);
    std::cin >> w;
    vector<vector<int>> v(n);
    for (int i{}, x, y; i < m; ++i) {
        std::cin >> x >> y, --x, --y;
        v[x].emplace_back(y);
    }
    meion [scc, id] = get_scc_dir(v);
    const int N = (int)scc.size();
    vector<uint8_t> sel(N);
    for (int i{}; i < N; ++i) {
        for (int x : scc[i]) {
            for (int to : v[x]) {
                if (x == to) {
                    goto suc;
                }
            }
        }
        if (false) suc: sel[i] = 1;
    }
    vector<pair<int, int>> minw(N, {inf<int>, 0});
    for (int i{}; i < N; ++i) {
        for (int x : scc[i]) {
            chmin(minw[i], pair{w[x], x});
        }
    }
    meion g = get_new_graph(scc, id, v);
    vector<int> in(n);
    for (int i{}; i < N; ++i) {
        for (int k : g[i]) {
            ++in[k];
        }
    }
    vector<int> s;
    for (int i{}; i < n; ++i) {
        if (in[id[i]] or i != minw[id[i]].second or sel[id[i]])
            s.emplace_back(w[i]);
    }
    sort(s, greater());
    s.resize(k);
    std::cout << qsum(s, 0ll) << '\n';
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