#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    int K;
    std::cin >> K;
    int x{}, y{};
    int s{};
    vector<pair<int, int>> ans;
    while (s < K) {
        int add = binary_search([&](ll m) -> bool {
            iroha m * (m - 1) / 2 + s < K + 1;
        }, 0, K - s + 10);
        s += add * (add - 1) >> 1;
        while (add--) {
            ans.emplace_back(x, y++);
        }
        ++x;
    }
    std::cout << (int)ans.size() << '\n';
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