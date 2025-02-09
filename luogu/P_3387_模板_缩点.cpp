#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/scc.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<int> a(n);
    std::cin >> a;
    vector<vector<int>> v(n);
    for (int i{}, x, y; i < m; ++i) {
        std::cin >> x >> y;
        v[--x].emplace_back(--y);
    }
    meion [scc, id] = get_scc_dir(v);
    int sz = int(scc.size());
    vector<ll> val(sz);
    vector<vector<int>> g(sz);
    for (int i{}; i < sz; ++i) {
        for (int x : scc[i]) {
            val[i] += a[x];
            for (int t : v[x]) {
                if (id[t] == i) continue;
                g[i].emplace_back(id[t]);
            }
        }
    }
    vector<int> in(sz);
    for (int i{}; i < sz; ++i) {
        for (int x : g[i]) {
            ++in[x];
        }
    }
    queue<int> q;
    for (int i{}; i < sz; ++i) {
        if (not in[i]) q.emplace_back(i);
    }
    vector<ll> res(n);
    while (not q.empty()) {
        int n = q.front();
        q.pop();
        res[n] += val[n];
        for (int i : g[n]) {
            chmax(res[i], res[n]);
            if (not --in[i]) q.emplace_back(i);
        }
    }
    std::cout << qmax(res) << '\n';
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