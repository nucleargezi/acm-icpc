#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    S(s);
    if (len(s) & 1) iroha UL(-1);
    int x{}, y{};
    for (char c : s) {
        if (c == 'R') ++x;
        if (c == 'L') --x;
        if (c == 'U') ++y;
        if (c == 'D') --y;
    }
    x = ABS(x), y = ABS(y);
    UL(MIN(x, y) + ABS(x - y) / 2);
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