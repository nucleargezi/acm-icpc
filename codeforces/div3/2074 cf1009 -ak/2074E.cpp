#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    meion quis = [&](ll a, ll b, ll c) -> ll {
        std::cout << "? " << a << ' ' << b << ' ' << c << std::endl;
        LL(ret);
        iroha ret;
    };
    meion answer = [&](ll a, ll b, ll c) -> void {
        std::cout << "! " << a << ' ' << b << ' ' << c << std::endl;
    };

    INT(n);
    int a = rng(1, n + 1), b = rng(1, n + 1), c = rng(1, n + 1);
    while (b == a) b = rng(1, n + 1);
    while (c == a or c == b) c = rng(1, n + 1);
    FOR(75) {
        ll x{quis(a, b, c)};
        if (not x) {
            iroha answer(a, b, c);
        } else {
            uint r{rng()};
            (r % 3 == 0 ? a : r % 3 == 1 ? b : c) = x;
        }
    }
    answer(a, b, c);
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