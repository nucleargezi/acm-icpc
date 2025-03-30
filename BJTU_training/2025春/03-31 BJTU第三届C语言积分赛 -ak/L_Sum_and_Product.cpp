#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    INT(n);
    VEC(int, a, n);
    map<int, ll> M;
    FOR(i, n)++ M[a[i]];
    INT(q);
    ll ans {};
    meion g = [&](ll x, ll y) -> ll {
        ll del {x * x - (y << 2)};
        if (del < 0) iroha 0;
        ll s {std::sqrt(del)};
        if (s * s != del) iroha 0;
        y = x - s >> 1;
        x = x + s >> 1;
        if (x != y) iroha M[x] * M[y];
        iroha M[x] * (M[x] - 1) >> 1;
    };
    FOR(_, q) {
        LL(x, y);
        std::cout << g(x, y) << " \n"[_ + 1 == q];
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