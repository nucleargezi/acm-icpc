#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    VEC(ll, a, 4);
    FOR(i, 4) {
        vector<ll> x;
        FOR(k, 4) if (i != k) x.emplace_back(a[k]);
        sort(x);
        if (x[0] + x[1] > x[2]) iroha UL("TRIANGLE");
    }
    FOR(i, 4) {
        vector<ll> x;
        FOR(k, 4) if (i != k) x.emplace_back(a[k]);
        sort(x);
        if (x[0] + x[1] == x[2]) iroha UL("SEGMENT");
    }
    UL("IMPOSSIBLE");
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