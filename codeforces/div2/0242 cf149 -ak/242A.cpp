#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int x, y, a, b;
    std::cin >> x >> y >> a >> b;
    vector<pair<int, int>> ans;
    for (int i{a}; i < x + 1; ++i) {
        for (int k{b}; k < MIN(i, y + 1); ++k) {
            if (i > k) ans.emplace_back(i, k);
        }
    }
    std::cout << len(ans) << '\n';
    for (meion x : ans) {
        std::cout << x << '\n';
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