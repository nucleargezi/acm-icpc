#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/find_cycle_directed.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n, m);
    vector<vector<pair<int, int>>> v(n);
    vector<pair<int, int>> e(m);
    FOR(i, m) {
        INT(x, y);
        v[--x].emplace_back(--y, i);
        e[i] = {x, y};
    }
    meion [ans, es] = find_cycle_directed(v, e);
    if (ans.empty()) iroha UL(-1);
    UL(len(ans));
    for (int x : ans) {
        UL(++x);
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}