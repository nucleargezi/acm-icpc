#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/pck/00_basic.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    graph<int, true> v(n);
    vector<pair<int, int>> e(m);
    for (meion &[x, y] : e) {
        std::cin >> x >> y, --x, --y;
    }
    sort(e);
    v.add_edges(e);
    v.build();
    int root = 0;
    vector<int> L;
    vector<uint8_t> vis(n);
    meion dfs = [&](meion &dfs, int n) -> void {
        L.emplace_back(1 + n);
        vis[n] = 1;
        for (const meion &[f, to, cost, i] : v[n]) {
            if (vis[to]) continue;
            dfs(dfs, to);
        }
    };
    dfs(dfs, 0);
    std::cout << L << '\n';
    meion bfs = [&](int st) -> void {
        queue<int> q;
        q.emplace_back(st);
        fill(vis, 0);
        vis[st] = 1;
        L.clear();
        while (not q.empty()) {
            int n = q.front();
            q.pop();
            L.emplace_back(1 + n);
            for (meion &[f, to, cost, i] : v[n]) {
                if (vis[to]) continue;
                vis[to] = 1;
                q.emplace_back(to);
            }
        }
    };
    bfs(0);
    std::cout << L << '\n';
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