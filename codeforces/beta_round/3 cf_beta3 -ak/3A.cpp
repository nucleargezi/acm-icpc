#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    S(s, t);
    int x{s[0] - 'a'}, y{s[1] - '1'}, xx{t[0] - 'a'}, yy{t[1] - '1'};
    int dx{xx - x}, dy{yy - y};
    UL(MAX(ABS(dx), ABS(dy)));
    while (dx or dy) {
        string mv;
        if (dx > 0) --dx, mv += 'R';
        else if (dx) ++dx, mv += 'L';
        if (dy > 0) --dy, mv += 'U';
        else if (dy) ++dy, mv += 'D';
        UL(mv);
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
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}