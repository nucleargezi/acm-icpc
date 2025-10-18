#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> dis(n);
    std::cin >> dis;

    graph<int, true> v(n);
    vector<tuple<int, int, int>> e;
    for (int a, b, c; std::cin >> a >> b >> c; ) {
        v.add(a, c, b);
        if (a != b) {
            v.add(b, c, a);
        }
    }
    v.build();

    vector<ll> cnt(n, 1);
    vector<uint8_t> vis(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    for (int i{}; i < n; ++i) q.emplace(dis[i], i);

    while (not q.empty()) {
        meion [d, n] = q.top();
        q.pop();
        if (vis[n]) continue;
        vis[n] = 1;
        for (meion [a, c, b, _] : v[n]) {
            if (vis[a] and vis[b]) {
                if (chmin(dis[c], dis[a] + dis[b])) {
                    cnt[c] = cnt[a] * cnt[b];
                    q.emplace(dis[c], c);
                } else if (dis[c] == dis[a] + dis[b]) {
                    cnt[c] += cnt[a] * cnt[b];
                }
            }
        }
    }
    std::cout << dis[0] << ' ' << cnt[0] << '\n';
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