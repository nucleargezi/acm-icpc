#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> v(m);
    for (int i{}, x, y; i < n; ++i) {
        std::cin >> x >> y;
        if (x > m) continue;
        v[m - x].emplace_back(y);
    }

    int ans{};
    priority_queue<int> q;
    for (int i{m}; i--; ) {
        for (int x : v[i]) {
            q.emplace(x);
        }
        if (q.empty()) continue;
        ans += q.top();
        q.pop();
    }
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // std::ifstream in("in"); std::cin.rdbuf(in.rdbuf());
    // std::ofstream ou("out"); std::cout.rdbuf(ou.rdbuf());
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}