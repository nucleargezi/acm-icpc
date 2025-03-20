#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<19260817>;
NAME MeIoN_is_UMP45() {
    S(a, b);
    mint x, y;
    for (char c : a) {
        x = x * 10 + c - '0';
    }
    for (char c : b) {
        y = y * 10 + c - '0';
    }
    UL(x / y);
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