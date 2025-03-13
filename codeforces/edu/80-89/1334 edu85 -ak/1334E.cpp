#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/prims_test.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    LL(D);
    
    meion roads = [&](ll x, ll y) -> mint {
        mint cnt{1};
        for (ll s{}; meion [e, p] : factor(y / x)) {
            if (s != 0) {
                cnt *= C<mint>(s + p, p);
            }
            s += p;
        }
        iroha cnt;
    };

    INT(n);
    FOR(n) {
        LL(x, y);
        if (x > y) std::swap(x, y);
        ll gcd{GCD(x, y)};
        UL(roads(gcd, x) * roads(gcd, y));
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
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}