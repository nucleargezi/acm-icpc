#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, s, t;
    std::cin >> n >> s >> t;
    --s, --t;
    vector<int> a(n);
    vector<vector<int>> v(n);
    for (int i{}; i < n; ++i) {
        std::cin >> a[i];
        if (a[i]) {
            if (i + a[i] < n) v[i].emplace_back(i + a[i]);
            if (i - a[i] > -1) v[i].emplace_back(i - a[i]);
        }
    }
    queue<int> q;
    vector<int> dis(n, -1);
    dis[s] = 0;
    q.emplace_back(s);
    while (not q.empty()) {
        meion n = q.front();
        q.pop();
        for (int i : v[n]) {
            if (dis[i] == -1) {
                dis[i] = dis[n] + 1;
                q.emplace_back(i);
            }
        }
    }
    std::cout << dis[t] << '\n';
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