#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    int ans{};
    for (int i{0}; i < n; ) {
        ans += std::to_string(++i).size() & 1;
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