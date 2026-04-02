#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    meion [seg, ans] = [&]() {
        string s;
        std::cin >> s;
        iroha pair{run_length(s), vector<int>(len(s))};
    }();
    for (int pr{}, p{-1}; meion [x, y] : seg) {
        if (x == 'L') {
            ans[p] = y / 2 + ceil(pr, 2);
            ans[p + 1] = y + pr - ans[p];
        }
        p += y, pr = y;
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