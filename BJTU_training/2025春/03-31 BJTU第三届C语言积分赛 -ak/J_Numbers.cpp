#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    LL(n);
    ll s{};
    meion f = [&](ll B) -> ll {
        ll res{}, x{n};
        while (x) {
            res += x % B;
            x /= B;
        }
        iroha res;
    };
    FOR(i, 2, n) {
        s += f(i);
    }
    ll x{s}, y{n - 2}, gcd{GCD(x, y)};
    UL(std::to_string(x / gcd) + "/" + std::to_string(y / gcd));
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