#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/exgcd.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(a, b, c);
    meion [f, x, y] = linear_solver(a, b, -c);
    if (f) UL(x, y);
    else UL(-1);
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