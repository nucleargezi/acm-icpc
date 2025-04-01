#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    int bit{topbit(n - 1) + 1};
    vector<vector<int>> ans(bit);
    FOR(i, n) FOR(k, bit) if (i >> k & 1) {
        ans[k].emplace_back(i + 1);
    }
    UL(bit);
    FOR(i, bit) UL(len(ans[i]), ans[i]);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}