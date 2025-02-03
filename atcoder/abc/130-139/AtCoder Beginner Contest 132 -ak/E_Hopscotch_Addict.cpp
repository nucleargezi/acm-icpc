#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> v(n * 3);
    meion add_edge = [&](int x, int y) -> void {
        v[x].emplace_back(y);
    };
    for (int i{}, x, y;i < m; ++i) {
        std::cin >> x >> y;
        --x, --y;
        add_edge(x, y + n);
        add_edge(x + n, y + n + n);
        add_edge(x + n + n, y);
    }
    int s, t;
    std::cin >> s >> t;
    --s, --t;
    queue<int> q;
    q.emplace_back(s);
    vector<int> dis(n * 3, inf<int>);
    dis[s] = 0;
    while (not q.empty()) {
        int n = q.front();
        q.pop();
        for (int i : v[n]) {
            if (not chmin(dis[i], dis[n] + 1)) continue;
            q.emplace_back(i);
        }
    }
    std::cout << (dis[t] == inf<int> ? -1 : dis[t] / 3) << '\n';
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