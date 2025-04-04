#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/16-out_circle.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    using RE = long double;
    using P = point<RE>;
    P a, b, c;
    IN(a, b, c);
    meion [O, R] = out_circle<RE>(a, b, c);
    constexpr RE eps = 1e-5;
    FOR(n, 3, 0721) {
        RE de = pi * 2 / n, x;
        x = ABS((a - O).angle() - (b - O).angle()) / de;
        if (ABS(x - std::round(x)) > eps) continue;
        x = ABS((c - O).angle() - (b - O).angle()) / de;
        if (ABS(x - std::round(x)) > eps) continue;
        iroha UL(R * R * n * std::sin(de) / 2);
    }
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(8);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    LL(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}