#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    S(s, x, y);
    int a{}, b{}, c{}, d{};
    FOR(i, len(s)) {
        if (not a and s.substr(i, MIN<ll>(len(x), len(s) - i)) == x) {
            a = 1;
            i += len(x) - 1;
            continue;
        }
        if (a and s.substr(i, MIN<ll>(len(y), len(s) - i)) == y) {
            b = 1;
        }
    }
    reverse(s);
    FOR(i, len(s)) {
        if (not c and s.substr(i, MIN<ll>(len(x), len(s) - i)) == x) {
            c = 1;
            i += len(x) - 1;
            continue;
        }
        if (c and s.substr(i, MIN<ll>(len(y), len(s) - i)) == y) {
            d = 1;
        }
    }
    if (MIN(a, b, c, d)) {
        UL("both");
    } else if (MIN(a, b)) {
        UL("forward");
    } else if (MIN(c, d)) {
        UL("backward");
    } else {
        UL("fantasy");
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