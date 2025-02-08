#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/find_cycle_directed.hpp"

void before() {}

// #define tests

NAME MeIoN_is_UMP45() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<pair<int, int>>> v(n);
    vector<pair<int, int>> e(m);
    for (int i{}, x, y; i < m; ++i) {
        std::cin >> x >> y;
        v[--x].emplace_back(--y, i);
        e[i] = {x, y};
    }
    meion [ans, es] = find_cycle_directed(v, e);
    if (ans.empty()) iroha std::cout << "-1\n", void();
    std::cout << int(ans.size()) << '\n';
    for (int x : ans) {
        std::cout << ++x << '\n';
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