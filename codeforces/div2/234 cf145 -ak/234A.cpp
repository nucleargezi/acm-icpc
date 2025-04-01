#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    S(s);
    vector<pair<int, int>> ans;
    FOR(i, n >> 1) {
        ans.emplace_back(i + 1, i + n / 2 + 1);
        if (s[i] == 'R' and s[i + n / 2] == 'L') {
            std::swap(ans.back().first, ans.back().second);
        }
    }
    FOR(i, n >> 1) UL(ans[i]);
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