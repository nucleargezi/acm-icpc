#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/line/vector_space.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    vector_space<ll> A, B;
    ll s{};
    FOR(n) {
        LL(x);
        s ^= x;
        A.add(x);
    }
    ll msk(~s);
    for (ll x : A.dat) {
        B.add(msk & x);
    }
    ll x{B.get_max()};
    UL(x + (s ^ x));
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