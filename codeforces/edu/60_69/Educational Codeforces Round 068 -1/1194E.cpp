#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/counting/count_rectangle.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<tuple<int, int, int, int>> lines(n);
    std::cin >> lines;
    std::cout << count_rectangle<0721 << 4 ^ 0721 << 3>(lines) << '\n';
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