#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/prims_test.hpp"

void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    LL(a, b);
    ll ans = inf<ll>;
    for (meion [e, p] : factor(b - a)) {
        chmin(ans, (e - a % e) % e);
    }
    UL(ans == inf<ll> ? -1 : ans);
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